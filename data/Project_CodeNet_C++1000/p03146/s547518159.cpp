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
  ll s;
  cin>>s;
  vector<bool> judge(1000000,false);
  ll a=s;
  ll ans;
  judge[s]=true;
  for(int i=2;i<10000000;i++){
    if(a%2==0){
      a/=2;
      if(judge[a]){
        ans=i;
        break;
      }
      else{
        judge[a]=true;
      }
    }
    else{
      a=3*a+1;
      if(judge[a]){
        ans=i;
        break;
      }
      else{
        judge[a]=true;
      }
    }
  }
  cout<<ans<<endl;
}
