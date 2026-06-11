#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ll n;cin>>n;
    string a;cin>>a;
    vector<vector<ll> > r(n+1,vector<ll>(26));
    rep(i,n){
      rep(j,26){
        r[i+1][j]=r[i][j];
      }
      r[i+1][a[i]-'a']=r[i][a[i]-'a']+1;
    }
    ll ans =0;
    ll MOD=1000000000+7;
    rep(i,n){
        ll ans1=1;
        int cnt=a[n-i-1]-'a';
        rep(j,26){
            if(cnt!=j){
            ans1*=(r[n-i][j]+1);
            ans1%=MOD;
            }
        }
        ans+=ans1;
        ans%=MOD;
    }
    cout<<ans<<endl;
}