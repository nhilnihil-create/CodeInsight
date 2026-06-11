//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  vl a(n),b(n),c(n),d(n);
  rep(i,n)cin>>a[i]>>b[i];
  rep(i,n)cin>>c[i]>>d[i];
  vector<P>R(n);
  rep(i,n){
    R[i].first=b[i];R[i].second=a[i];
  }
  vector<P>B(n);
  rep(i,n){
    B[i].first=c[i];B[i].second=d[i];
  }
  sort(R.begin(),R.end());
  reverse(R.begin(),R.end());
  sort(B.begin(),B.end());
  vector<bool>unuse(n,true);
  vector<bool>unuse2(n,true);
  
  ll count=0;
  rep(i,n){
    rep(j,n){
      if(R[j].first<B[i].second && R[j].second<B[i].first && unuse[j] &&unuse2[i]){
        unuse[j]=false;
        unuse2[i]=false;
        count++;
        break;
      }
    }
  }
  cout<<count<<endl;
}
        
    