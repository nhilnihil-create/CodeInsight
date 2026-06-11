#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; vector<ll> vec; vec.pb(-1); cin >> n >> k;
    for(int i = 0; i < n; i++){
        ll t; cin >> t; vec.pb(t);
    }
    ll res = 1e15;
    for(int i = 1; i <= n-k+1; i++){
        ll l = vec[i], r = vec[i+k-1];
        if(l <= 0 && r >= 0){
            res  = min(res, (ll)min(abs(l), abs(r))*2 + (ll)max(abs(l), abs(r)) );
        }
        else if(l <= 0 && r <= 0){
            res = min(res, (ll)max(abs(l), abs(r)));
        }
        else{
            res = min(res , (ll)max(abs(l),abs(r)));
        }
    }
    cout << res << endl;
    return 0;
}
