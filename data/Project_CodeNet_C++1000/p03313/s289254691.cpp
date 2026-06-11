#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;

signed main(){
    ll n;cin>>n;
    vector<ll>a(1LL<<n);
    rep(i,1LL<<n)cin>>a[i];
    vector<ll>ma1(1LL<<n);
    vector<ll>ma2(1LL<<n);
    REP(i,1,1LL<<n){
        for(int j=i;;j=(j-1)&i){
            if(a[j]>=ma1[i]){
                ma2[i]=ma1[i];
                ma1[i]=a[j];
            }else if(a[j]>=ma2[i]){
                ma2[i]=a[j];
            }
            if(j==0)break;
        }
    }
    ll ans=0;
    REP(i,1,1LL<<n){
        ans=max(ans,ma1[i]+ma2[i]);
        cout<<ans<<endl;
    }
}