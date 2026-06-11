#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
 
using namespace std;
 
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
 
long gcd(long a, long b){
	if (a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
 
long lcm(long a, long b){
	return (a*b) / gcd(a,b);
}
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a < b) { a = b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a > b) { a = b; return 1; } return 0; }
 
typedef long long ll;
 
const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-10;

int n, k;

int main(){
	cin >> n >> k;
	
	cout << n-k+1 << endl;
	
	return 0;
}