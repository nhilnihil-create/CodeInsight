#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>>price(n);
    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        price[i]=make_pair(a,b);
    }
    sort(price.begin(),price.end());
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(price[i].second<m){
            m-=price[i].second;
            ans+=price[i].first*price[i].second;
        }
        else{
            ans+=price[i].first*m;
            m=0;
        }

        if(m==0){
            break;
        }
    }
    cout << ans << endl;
}
