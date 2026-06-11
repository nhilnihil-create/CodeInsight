#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define sum(a) accumulate(a.begin(),a.end(),0LL)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> p(m), y(m);
    rep(i,m) cin >> p[i] >> y[i];

    map<pair<ll,ll>,ll> mp;
    for(int i = 0; i < m; i++){
        mp[make_pair(p[i],y[i])];
    }

    vector<ll> cnt(n,0);
    for(auto x:mp){
        cnt[x.first.first-1]++;
        mp[x.first] = cnt[x.first.first-1];
        //cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }

    for(int i = 0; i < m; i++){
        cout << setfill('0') << right << setw(6) << p[i];
        cout << setfill('0') << right << setw(6) << mp[make_pair(p[i], y[i])] << endl;
    }

    //for(auto x:mp) cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    //for(auto x:cnt) cout << x << " "; cout << endl;
}