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
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL H,W,N;
LL Sr,Sc;
string S,T;

string ans = "NO";

void solve(){
	map<char,LL> num_T,num_A;
	//高橋くんが左に落としにいくとき
	int start_c = Sc;
	for(int i=0;i<N;i++){
		if(S[i]=='L'){
			start_c--;
			if(start_c<=0) return;
		}
		if(T[i]=='R'){
			if(start_c<=W-1)start_c++;
		}
	}
	//右に落としにいくとき
	start_c = Sc;
	for(int i=0;i<N;i++){
		if(S[i]=='R'){
			start_c++;
			if(start_c>W) return;
		}
		if(T[i]=='L'){
			if(start_c>=2)start_c--;
		}
	}
	//上に落としにいくとき
	int start_r = Sr;
	for(int i=0;i<N;i++){
		if(S[i]=='U'){
			start_r--;
			if(start_r<=0) return;
		}
		if(T[i]=='D'){
			if(start_r<=H-1)start_r++;
		}
	}
	//下に落としにいくとき
	start_r = Sr;
	for(int i=0;i<N;i++){
		if(S[i]=='D'){
			start_r++;
			if(start_r>H) return;
		}
		if(T[i]=='U'){
			if(start_r>=2)start_r--;
		}
	}
	ans = "YES";
}
 
int main(){
    cin >> H >> W >> N;
    cin >> Sr >> Sc;
    cin >> S;
    cin >> T;

    solve();

	cout << ans << endl;
    return 0;
}