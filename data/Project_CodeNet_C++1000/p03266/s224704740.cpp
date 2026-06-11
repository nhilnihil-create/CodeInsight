#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    ll ans=0;
    if(k==1){
        ans=n*n*n;
        cout << ans << endl;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        ll j;
        ll ibai=i/k;
        j=k-(i-k*ibai);
        ll l=k-j;
        if(l==0) l+=k;
        ll lcopy=n-l;
        if((i+l)%k!=0) continue;
        ll lcnt=lcopy/k+1;
        ll jcopy=n-j;
        ll jcnt=jcopy/k+1;
        ans+=lcnt*jcnt;
    }
    cout << ans << endl;
}