#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,k;
    cin >> n >> k;
    ll v[n];
    for(ll i=0;i<n;i++) cin >> v[i];
    ll res=0;
    for(ll a=0;a<=min(n,k);a++){
        for(ll b=0;b+a<=min(n,k);b++){
            ll cur=0;
            vector<ll> vec;
            for(ll i=0;i<a;i++){
                vec.push_back(v[i]);
                cur+=v[i];
            }
            for(ll i=0;i<b;i++){
                vec.push_back(v[n-1-i]);
                cur+=v[n-1-i];
            }
            sort(vec.begin(),vec.end());
            for(ll i=0;i<min(k-a-b,(ll)vec.size());i++){
                if(vec[i]<0) cur-=vec[i];
            }
            res=max(res,cur);
        }
    }
    cout << res << endl;
}
