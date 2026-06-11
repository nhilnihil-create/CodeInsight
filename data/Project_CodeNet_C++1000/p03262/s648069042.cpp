#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; ll x; cin >> n >> x;
    vector<ll> vec;
    for(int i = 0; i < n; i++){
        ll t; cin >> t; vec.pb(t);
    }
    vec.pb(x); sort(vec.begin(),vec.end());
    vector<ll> vec2;
    for(int i = 0; i < vec.size()-1; i++){
        vec2.pb(vec[i+1]-vec[i]);
    }
    ll res = vec2[0];
    for(int i = 1; i < vec2.size(); i++){
        res = __gcd(res, vec2[i]);
    }
    cout << res << endl;
    return 0;
}
