#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
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

        if(a[i]==a[i+1]) ans+=a[i+1];
        else if(a[i]>a[i+1]) ans+=a[i+1];
        else ans++;
    }

    cout<<ans<<endl;
}