#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <algorithm>

/*
#include <atcoder/all>
using namespace atcoder;
*/

using namespace std;

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define repr(i, n) for (ll i = n - 1; i >= 0; i--)
#define repr1(i, n) for (ll i = n; i > 0; i--)
#define FOR(i, j, n) for (ll i = j; i < n; i++)

const ll MOD = 1000000007; // 10^9+7
const ll MOD2 = 998244353;
const ll INF = 10000000000;

int main(void){
    ll n;
    cin >> n;

    vector<string > s(n);
    vector<ll> count(5,0);
    char march[5] = {'M','A','R','C','H'};
    rep(i,n){
        cin >> s[i];
        rep(j,5){
            if(s[i][0] == march[j]) count[j]++;
        }
    }

    ll ans = 0;

    for(ll i=0; i<5; i++){
        for(ll j=i+1; j<5; j++){
            for(ll k=j+1; k<5; k++){
                ans += count[i]*count[j]*count[k];
            }
        }
    }

    cout << ans << endl;
}