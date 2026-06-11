#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> vec;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
        vec.push_back(make_pair(a[i],1));
    }
    for(ll i=0;i<m;i++){
        ll b,c;
        cin >> b >> c;
        vec.push_back(make_pair(c,b));
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    ll res=0;
    ll count=0;
    for(ll i=0;i<vec.size();i++){
        if(count+vec[i].second<n){
            res+=vec[i].first*vec[i].second;
            count+=vec[i].second;
        }
        else{
            res+=vec[i].first*(n-count);
            break;
        }
    }
    cout << res << endl;
}
