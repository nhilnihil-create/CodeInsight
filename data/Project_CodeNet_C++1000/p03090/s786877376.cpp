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
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll n;cin>>n;
  vector<P>res;
  ll dame=n;
  if(n%2==1)dame--;
  for(ll i=1;i<n;i++){
    for(ll j=i+1;j<=n;j++){
      if(j==dame)continue;
      res.push_back(P(i,j));
    }
    dame--;
  }
  cout<<res.size()<<endl;
  for(auto p:res){
    cout<<p.first<<" "<<p.second<<endl;
  }

}