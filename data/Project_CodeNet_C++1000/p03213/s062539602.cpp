#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

ll nCr(ll n, ll r) {
	ll ans = 1;
	for (ll i = n; i > n - r; --i) {
		ans = ans * i;
	}
	for (ll i = 1; i < r + 1; ++i) {
		ans = ans / i;
	}
	return ans;
}

int main() {
    int n;
    cin >> n;
    map<ll, ll> mp;
    REP(i, n){
        int now = i;
        for(int j = 2; j * j <= i; j++){
            while(now % j == 0){
                mp[j]++;
                now /= j;
            }
        }
        if(now != 1)mp[now]++;
    }
    int t=0, f=0, tf=0, of=0, sf=0;
    for(auto x : mp){
        if(x.second >= 2)t++;
        if(x.second >= 4)f++;
        if(x.second >= 24)tf++;
        if(x.second >= 14)of++;
        if(x.second >= 74)sf++;
    }
    
    cout << nCr(f, 2) * (t-2) + tf * (t-1) + of * (f-1) + sf<< endl;
}  