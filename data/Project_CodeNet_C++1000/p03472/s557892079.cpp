#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
 

int main(){
    int n;
    ll h;
    cin>>n>>h;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];

    sort(all(b));
    sort(all(a));
    reverse(all(b));
    ll ans=0;
    rep(i,n){
        if(b[i]>a[n-1]){
            h-=b[i];
            ans++;
            if(h<=0){
                cout<<ans<<endl;
                return 0;
            }
        }
    }

    ans+=(h+a[n-1]-1)/a[n-1];
    cout<<ans<<endl;
}
