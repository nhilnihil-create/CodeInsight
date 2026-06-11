#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}


int main(void)
{
    ll n,ans=0;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a]++;
    }
    for(auto i:mp){
        ll tmp;
        if(i.second-i.first >= 0) tmp = i.second-i.first;
        else tmp = i.second;
        ans += min(i.second, tmp);
    }
    cout << ans << endl;
    return 0;
}