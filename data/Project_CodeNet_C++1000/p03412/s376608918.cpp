#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
ll a[200010],b[200010];
vector<ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,j,n,ans = 0,k = 1;
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    for(i=0;i<n;i++) cin >> b[i];
    for(i=0;i<29;i++){
        k *= 2;
        ll sum = 0;
        v.clear();
        for(j=0;j<n;j++) v.push_back(b[j]%k);
        sort(v.begin(),v.end());
        for(j=0;j<n;j++){
            ll x = a[j]%k;
            if(x<k/2) sum += (upper_bound(v.begin(),v.end(),k-1-x) - lower_bound(v.begin(),v.end(),k/2 - x));
            if(x>=k/2) sum += n - (lower_bound(v.begin(),v.end(),k/2*3-x) - v.begin()) + (upper_bound(v.begin(),v.end(),k-1-x) - v.begin());
        }
        if(sum&1) ans += k/2;
    }
    cout << ans << endl;
}