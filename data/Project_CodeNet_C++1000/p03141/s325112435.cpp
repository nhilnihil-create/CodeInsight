#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pl;
#define all(a) (a).begin(),(a).end()
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,n) for(ll (i)=(n)-1;(i)>=0;i--)
#define SHOW(x) cout << #x << ": " << x << endl;
const ll INF=1e18,MOD = 1e9+7;
const int iINF = 1e9;

int main(){
    ll n,ans = 0;
    cin>>n;
    vector<P>a(n);
    rep(i,n)cin>>a[i].first>>a[i].second;
    sort(all(a),[&](P a, P b){return a.first+a.second > b.first+b.second;});
    rep(i,n){
        if(i%2 == 0)ans += a[i].first;
        else ans -= a[i].second;
    }
    cout<<ans<<endl;
}
