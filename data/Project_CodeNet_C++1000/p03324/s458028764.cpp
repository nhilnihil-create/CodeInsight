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
  ll D,N;
  cin>>D>>N;
  if(D==0){
    if(N!=100){
      cout<<N<<endl;
    }
    else{
      cout<<101<<endl;
    }
  }
  else if(D==1){
    if(N!=100){
      cout<<100*N<<endl;
    }
    else{
      cout<<10100<<endl;
    }
  }
  else if(D==2){
    if(N==100){
      N++;
    }
    cout<<10000*N<<endl;
  }
}
