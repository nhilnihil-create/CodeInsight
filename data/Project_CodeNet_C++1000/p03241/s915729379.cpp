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
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

vector<ll> get_prime(ll n){
	vector<ll> prime;
	
	for(ll i=1; i*i<=n; ++i){
		if(n%i!=0) continue;
		
		prime.push_back(i);
		if(i!=n/i) prime.push_back(n/i);
	}
	
	return prime;
}

int main(){
	ll n, m;
	cin >> n >> m;
	
	vector<ll> prime = get_prime(m);
	
	sort(prime.begin(),prime.end(),greater<ll>());
	
	REP(i,prime.size()){
		if(m/prime[i] >= n){
			cout << prime[i] << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	
	return 0;
}