#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int s[510][510];
int main(){
    int n,m,q;cin>>n>>m>>q;
    int l,r;
    for (int i=0; i<m; ++i){
        cin>>l>>r;
        for (int j=r; j<=500; ++j)++s[l][j];//累積和は後にふつうに求めたほうがいいかもしれないです。今回はどちらでも余裕
    }
    int ans;
    for (int i=0; i<q; ++i){
        cin>>l>>r;
        ans=0;
        for (int j=l; j<=r; ++j)
            ans+=s[j][r]-s[j][l-1];
        cout<<ans<<endl;
    }
}