#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")



int main() {

    ll n,m,a,b; cin >> n >> m;
    ll ans = 0;

    map<ll,ll> mp;
    set<ll, greater<ll>> st;

    rep(i,n){
        cin >> a;
        if(mp.count(a) == 0) mp[a] = 1;
        else mp[a] ++;
        st.insert(a);
    }
    rep(i,m){
        cin >> a >> b;
        if(mp.count(b) == 0)mp[b] = a;
        else mp[b] += a;
        st.insert(b);
    }



    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        if(n > mp[*itr]){
            ans += mp[*itr]*(*itr);
            n -= mp[*itr];
        }else{
            ans += n*(*itr);
            cout << ans;
            return 0;
        }
    }

    return 0;
}
