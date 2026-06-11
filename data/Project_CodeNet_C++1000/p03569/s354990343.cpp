//g++ -std=c++14 test.cpp -o test.out
 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;
 
string S;
 
int ans = 0;
 
void solve(){
	//まずSからxを抜いたものを考え、
	string S_without_x = "";
	for(int i=0;i<S.size();i++){
		if(S[i]!='x') S_without_x += S[i];
	}
	int N = S_without_x.size();
	if(N==0) return;
	//それが回文なのかを判定
	for(int i=0;i<N/2;i++){
		if(S_without_x[i]!=S_without_x[N-1-i]){
			ans = -1;
			return;
		}
	}
	//回文であれば以下を実行
	//xなしのSの一番真ん中の文字
	//が、Sにおいてはどのインデックスに位置するのかを
	//S_middle_indexに保管
	int S_middle_index = 0;
	for(int i=0;i<=N/2;i++){
		while(S[S_middle_index]=='x') S_middle_index++;
		S_middle_index++;
	}
	S_middle_index--;
	//cout << S_middle_index << " " << S[S_middle_index] << endl;
	//return;
	vector<int> x_num;
	int x_seq = 0;//連続するxの数
	for(int i=0;;i++){
		if(S[i]=='x'){
			x_seq++;
		}else{
			x_num.push_back(x_seq);
			x_seq = 0;
		}
		if(i==S_middle_index) break;
	}

	x_seq = 0;
	int x_num_index = 0;
	for(int i=S.size()-1;;i--){
		if(S[i]=='x'){
			x_seq++;
		}else{
			ans += abs(x_num[x_num_index]-x_seq);
			x_seq = 0;
			x_num_index++;
		}
		if(i==S_middle_index) break;
	}
}
 
int main(){
    cin >> S;
 
    solve();
 
    cout << ans << endl;
    return 0;
}