#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){

    ll n; cin >> n;
    vector<ll> s(n+5,0);
    ll tmp;
    map<ll,ll> mp;
    mp[0]++;
    rep(i,n){
        // s[i+1] : A_iまでの和
        cin >> tmp;
        s[i+1] = s[i] + tmp;
        mp[s[i+1]] ++;
    }

    ll ans=0;
    for(auto itr : mp){
        // cout << itr.first << " " << itr.second <<  endl;
        tmp = itr.second;
        ans += tmp*(tmp-1)/2;
    }

    cout << ans << endl;




    return 0;
}