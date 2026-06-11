#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
// typedef long double ldouble;

using Graph = vector<vector<int>>;

// int ctoi(const char c){
//   if('0' <= c && c <= '9') return (c-'0');
//   return -1;
// }

// int gcd(int a, int b){
//   int ma = max(a,b);
//   int mi = min(a,b);
//   if(mi == 0) return ma;

//   return gcd(mi, ma%mi);
// }

// llong POW(llong a, llong b){
//   if(b == 0) return 1;
//   else{
//     if(b%2 == 0) return POW(a * a % MOD, b / 2) % MOD;
//     else return a * POW(a * a % MOD, b / 2) % MOD;
//   }
// }

int main(){
	int S;
	cin >> S;
	int top = S/100;
	int bottom = S%100;
	if(top==0 && bottom==0) cout << "NA" << endl;
	else if(top==0 && bottom<13) cout << "YYMM" << endl;
	else if(top==0 && bottom>12) cout << "NA" << endl;
	else if(top<13 && bottom==0) cout << "MMYY" << endl;
	else if(top>12 && bottom==0) cout << "NA" << endl;
	else if(top<13 && bottom <13) cout << "AMBIGUOUS" << endl;
	else if(top<13 && bottom > 12) cout << "MMYY" << endl;
	else if(top>12 && bottom<13) cout << "YYMM" << endl;
	else cout << "NA" << endl;
}