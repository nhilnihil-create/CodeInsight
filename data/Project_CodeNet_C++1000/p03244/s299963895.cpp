#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll n;
    cin >> n;
    VL v(n);
    rep(i, 0, n) cin >> v[i];
    ll ans = 0;
    map<ll, ll> odd, even;
    for(ll i = 0; i < n; i += 2) odd[v[i]]++;
    for(ll i = 1; i < n; i += 2) even[v[i]]++;
    ll omx = 0, osmx = 0, emx = 0, esmx = 0;
    ll oid = 0, osid = 0, eid = 0, esid = 0;
    auto f = [&](pair<ll, ll> e) {
        if(omx < e.second) {
            osmx = omx;
            osid = oid;
            omx = e.second;
            oid = e.first;
        }else if(osmx < e.second) {
            osmx = e.second;
            osid = e.first;
        }
    };
    auto g = [&](pair<ll, ll> e) {
        if(emx < e.second) {
            esmx = emx;
            esid = eid;
            emx = e.second;
            eid = e.first;
        }else if(esmx < e.second) {
            esmx = e.second;
            esid = e.first;
        }
    };
    for(auto e : odd) f(e);
    for(auto e : even) g(e);
    cerr << oid << " " << eid << endl;
    if(oid == eid) {
        if(-omx + osmx > -emx + esmx) {
            cout << n - (osmx + emx) << endl;
        } else {
            cout << n - (omx + esmx) << endl;
        }
    }else{
        cout << n - (omx + emx) << endl;
    }
    return 0;
}