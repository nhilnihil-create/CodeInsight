#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;cin>>n>>k;
    vector<ll> c(40,0),kb(40);
    rep(i,40){
        kb[40-i-1]=k%2;
        k/=2;
    }
    rep(i,n){
        ll a;cin>>a;
        rep(j,40){
            c[40-j-1]+=a%2;
            a/=2;
        }
    }
    vector<ll> dp0(41,0),dp1(41,-1);
    rep(i,40){
        if(kb[i]==0){
            dp0[i+1]=dp0[i]*2+c[i];
            if(dp1[i]!=-1)dp1[i+1]=dp1[i]*2+max(c[i],n-c[i]);
        }else{
            dp0[i+1]=dp0[i]*2+n-c[i];
            if(dp1[i]!=-1)dp1[i+1]=max(dp0[i]*2+c[i],dp1[i]*2+max(c[i],n-c[i]));
            else dp1[i+1]=dp0[i]*2+c[i];
        }
    }
    cout<<max(dp0[40],dp1[40])<<endl;
    return 0;
}