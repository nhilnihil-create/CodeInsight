#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int prime[101];

int main(){
	int n;
	cin >> n;
	
	for(int i=2; i<=n; i++){
		int num = i;
		for(int k=2; k*k<=num; k++){
			while(num%k==0){
				prime[k]++;
				num /= k;
			}
		}
		prime[num]++;
	}
	
	// 75 = 3 * 25 = 5 * 15 = 3 * 5 * 5
	int ans=0;
	FOR(i,2,n+1){
		if(prime[i] >= 74) ans++;
	}
	
	FOR(i,2,n+1){
		FOR(j,2,n+1){
			if(i==j) continue;
			
			if(prime[i]>=2 && prime[j]>=24) ans++;
			if(prime[i]>=4 && prime[j]>=14) ans++;
		}
	}
	
	FOR(i,2,n+1){
		FOR(j,2,n+1){
			FOR(k,j+1,n+1){
				if(i==j || i==k) continue;
				
				if(prime[i]>=2 && prime[j]>=4 && prime[k]>=4) ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}