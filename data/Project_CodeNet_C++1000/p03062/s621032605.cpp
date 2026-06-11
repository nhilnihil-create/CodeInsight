#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;

    ll ans=0;
    ll mi=1LL<<60;
    bool ok=false;
    int cnt=0;
    rep(i,n){
        ll a;
        cin>>a;
        ans+=abs(a);
        mi=min(mi,abs(a));
        if(a==0) ok=true;
        if(a<0) cnt++;
    }

    if(ok) cout<<ans<<endl;
    else if(cnt%2==0) cout<<ans<<endl;
    else cout<<ans-2*mi<<endl;
}
