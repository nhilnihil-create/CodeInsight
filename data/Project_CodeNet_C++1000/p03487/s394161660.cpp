#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const int MAX = 100000;
static const int NIL = -1;
using namespace std;


int main() {

    ll n; cin >> n;
    map<ll,ll> mp;
    set<ll> st;
    ll ans = 0;

    rep(i,n){
        ll tmp; cin >> tmp;
        st.insert(tmp);
        if(mp.count(tmp) == 0) mp[tmp] = 1;
        else mp[tmp] ++;
    }

    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        ll tmp = *itr;


        if(mp[tmp] >= tmp && mp[tmp]-tmp < mp[tmp] - 0) ans += abs(mp[tmp]-tmp);
        else ans += abs(mp[tmp]-0);
        //ans += min(abs(mp[tmp]-tmp),abs(mp[tmp]-0));
    }

    cout << ans;

    return 0;
}
