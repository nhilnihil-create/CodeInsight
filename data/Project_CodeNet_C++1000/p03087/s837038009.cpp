#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    ll n,q; cin >> n >> q;
    string s; cin >> s;
    ll l,r;

    char prev = 'b';
    vector<int> sum(n+1,0);
    vector<pair<ll,ll>> v(q);


    rep(i,n) {
        if(prev == 'A' && s[i] == 'C') {
            sum[i+1] = sum[i] + 1;
        }else{
            sum[i+1] = sum[i];
        }
        prev = s[i];
    }

    rep(i,q) {
        cin >> v[i].first >> v[i].second;
    }

    rep(i,q){
        cout << sum[v[i].second] - sum[v[i].first] << endl;
    }
    return 0;
}
