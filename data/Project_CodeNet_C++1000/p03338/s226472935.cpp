#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N;
  cin>>N;
  string s;
  cin>>s;
  ll ans=0;
  
  for(int i=1;i<N;i++){
    ll count=0;
    
    for(char c='a';c<='z';c++){
      bool left=false,right=false;
      
      for(int j=0;j<i;j++){
        if(s[j]==c) left=true;
      }
      
      for(int j=i;j<N;j++){
        if(s[j]==c) right=true;
      }
      
      if(left&&right) count++;
    }
    ans=max(ans,count);
  }
  cout<<ans<<endl;
      
}