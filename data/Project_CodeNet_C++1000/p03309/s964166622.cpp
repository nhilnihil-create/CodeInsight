#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
        a[i]-=(i+1);
    }
    sort(a.begin(),a.end());
    ll mid=n/2;
    ll ans=0;
    ll b=a[mid];
    for(ll i=0;i<n;i++){
        a[i]-=b;
        if(a[i]<0) ans-=a[i];
        else ans+=a[i];
    }
    cout << ans << endl;
}
