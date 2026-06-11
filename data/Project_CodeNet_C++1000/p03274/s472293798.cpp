#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>x(n);
    ll ans=INF;
    rep(i,0,n){
        cin>>x.at(i);
    }
    rep(i,0,n-k+1){
        ans=min(ans,abs(x.at(i))+abs(x.at(i)-x.at(i+k-1)));
    }
    for(int i=n-1;i>=k-1;i--){
        ans=min(ans,abs(x.at(i))+abs(x.at(i)-x.at(i-k+1)));
    }
    cout<<ans<<endl;
return 0;
}