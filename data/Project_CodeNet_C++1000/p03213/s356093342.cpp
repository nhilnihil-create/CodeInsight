#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

map<ll, ll> prime_factor(ll n){
	map<ll, ll> res;
	for(ll i = 2; i*i <= n; i++){
		while(n%i == 0){
			res[i]++;
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<ll, ll> mp;
    for(int i = 1; i <= n; ++i){
        for(auto p : prime_factor(i)){
            mp[p.first] += p.second;
        }
    }
    ll c75 = 0, c25 = 0, c15 = 0, c5 = 0, c3 = 0;
    for(int i = 1; i <= n; ++i){
        if(mp[i] >= 74) ++c75;
        if(mp[i] >= 24) ++c25;
        if(mp[i] >= 14) ++c15;
        if(mp[i] >= 4) ++c5;
        if(mp[i] >= 2) ++c3;
    }
    ll ans = c75 + c25*(c3-1) + c15*(c5-1) + c5*(c5-1)*(c3-2)/2;
    cout << ans << endl;
    return 0;
}