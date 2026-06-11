#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
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

map<int, int> cnt;

int num(int m){
    int res = 0;
    for(auto p : cnt){
        if(p.second >= m-1) res++;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        map<ll, ll> pf = prime_factor(i);
        for(auto p : pf){
            cnt[p.first] += p.second;
        }
    }
    ll ans = num(75) + num(25)*(num(3)-1) + num(15) * (num(5)-1)
        + num(5) * (num(5)-1) * (num(3) - 2) / 2;
    cout << ans << endl;
	return 0;
}