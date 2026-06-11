#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;
    pair<ll, ll> cost[n];
    rep(i, 0, n){
        ll a, b;
        cin >> a >> b;
        cost[i].first = a + b;
        cost[i].second = a;
    }

    sort(cost, cost + n, greater<pair<ll, ll>>());

    ll x = 0, y = 0;
    rep(i, 0, n){
        if(i % 2 == 0){
            x += cost[i].second;
        }else{
            y += cost[i].first - cost[i].second;
        }
    }

    cout << x - y << endl;
    return 0;
}
