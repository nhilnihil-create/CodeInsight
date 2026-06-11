#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  ll n,m,q;
  cin>>n>>m>>q;
  vector<vector<ll>> v(n+5,vector<ll>(n+5,0));
  vector<vector<ll>> s(n+5,vector<ll>(n+5,0));
  vector<vector<ll>> S(n+5,vector<ll>(n+5,0));


  rep(i,m){
    ll l1,r1;
    cin>>l1>>r1;
    l1;r1;
    v[l1][r1]+=1;
  }
  rep(i,n){
    s[1][i]=v[1][i];
  }
  rep(i,n){
    s[i][1]=v[i][1];
  }
  rep(i,n+1)rep(j,n){
    s[i][j+1]=s[i][j]+v[i][j+1];
  //  cout<<s[i][j+1]<<' '<<i<<' '<<j+1<<endl;
  }
  S=s;
  rep(i,n)rep(j,n+1){
    S[i+1][j]=S[i+1][j]+S[i][j];
  //  cout<<S[i+1][j]<<' '<<i+1<<' '<<j<<endl;
  }
  rep(i,n+1)rep(j,n+1){
  //  S[i+1][j]=S[i+1][j]+S[i][j];
//    cout<<S[i][j]<<' '<<i<<' '<<j<<endl;
  }
  rep(i,q){
    ll p1,q1;
    cin>>p1>>q1;
    p1;q1;

    ll t1,t2,t3,t4;
    t1=S[q1][q1];
    t2=S[p1-1][q1];
    t3=S[q1][p1-1];
    t4=S[p1-1][p1-1];
    ll ans=t1-t2-t3+t4;
    cout<<ans<<endl;
  }


}
