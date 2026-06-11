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
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    if(a[0]!=0){
        cout<<-1<<endl;
        return 0;
    }

    ll ans=0;
    rep(i,n-1){
        if(a[i+1]-a[i]>1){
            cout<<-1<<endl;
            return 0;
        }

        if(a[i+1]<=a[i]) ans+=a[i+1];
        else ans++;
    }

    cout<<ans<<endl;
}