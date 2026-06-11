//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,C;cin>>n>>C;
  vvl d(C,vl(C));
  rep(i,C){
    rep(j,C)cin>>d[i][j];
  }
  vvl c(n,vl(n));
  rep(i,n){
    rep(j,n){
      cin>>c[i][j];
      c[i][j]--;
    }
  }
  vvl data(3);
  rep(i,n){
    rep(j,n)data[(i+j+2)%3].push_back(c[i][j]);
  }
  vector<vector<P> > MIN(3);
  rep(i,3){
    rep(j,C){
      ll sum=0;
      for(auto x:data[i]){
        sum+=d[x][j];
      }
      MIN[i].push_back(make_pair(sum,j));
    }
  }
  //rep(i,3){
    //rep(j,MIN[i].size())cout<<MIN[i][j].first<<" "<<MIN[i][j].second<<" ";
    //cout<<endl;
  //}
  rep(i,3)sort(MIN[i].begin(),MIN[i].end());
  ll ans=INF;
  rep(i,3){
    rep(j,3){
      rep(k,3){
        if(MIN[0][i].second==MIN[1][j].second||MIN[1][j].second==MIN[2][k].second||MIN[2][k].second==MIN[0][i].second)continue;
        ans=min(ans,MIN[0][i].first+MIN[1][j].first+MIN[2][k].first);
      }
    }
  }
  cout<<ans<<endl;
}
    
    