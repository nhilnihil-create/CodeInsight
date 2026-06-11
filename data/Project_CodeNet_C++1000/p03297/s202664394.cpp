//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc026/tasks/agc026_b

//ポイント：
//X増やしてY減らすみたいな操作では、XとYのgcdに注目してみる

//参考：
//https://betrue12.hateblo.jp/entry/2018/07/15/010448
//↑で紹介している風に実験するとわかるが
//C<A-Bx+Dy<B
//が成立するようなx,yの組が存在すれば永遠に買い続けられない
//これはつまりC<A+gcd(B,D)z<Bが成立するようなzが
//存在するかを確かめればいいことになる

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
#include <stack>
#include <map> 
#include <unordered_map> 
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

LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b) { return a/gcd(a,b)*b;}

int T;
LL A[300],B[300],C[300],D[300];

string ans[300];

void solve(){
	for(int i=0;i<T;i++){
		if(B[i]>D[i] || A[i]<B[i]){
			ans[i] = "No";
			continue;
		}
		if(B[i]<=C[i]+1){
			ans[i] = "Yes";
			continue;
		}
		LL G = gcd(B[i],D[i]);

		LL lower;
		if((C[i]-A[i])%G==0) lower = (C[i]-A[i])/G + 1LL;
		else{
			lower = (C[i]-A[i])/G;
			if(C[i]-A[i]>0) lower++;
		}

		LL upper;
		if((B[i]-A[i])%G==0) upper = (B[i]-A[i])/G - 1LL;
		else{
			upper = (B[i]-A[i])/G;
			if(C[i]-A[i]<0) upper--;
		}

		if(upper-lower>=0) ans[i] = "No";
		else ans[i] = "Yes";
	}
}

int main(){
    cin >> T;
    for(int i=0;i<T;i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    solve();

    for(int i=0;i<T;i++)cout << ans[i] << endl;
    return 0;
}