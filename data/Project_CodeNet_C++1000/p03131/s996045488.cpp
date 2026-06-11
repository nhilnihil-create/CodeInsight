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
  ll k,a,b;cin>>k>>a>>b;
  ll ans=0;
  ll MAX=k+1;
  
  if(k>=a&&b-a>0){
    k-=a-1;
    ans=a;
    ans+=(k/2*(b-a)+k%2);
  }
  cout<<max(ans,MAX)<<endl;
}