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
  ll a,b;
  cin>>a>>b;
  string s;
  cin>>s;
  bool judge=false;
  if(s[a]=='-'&&s.size()==a+b+1) judge=true;
  for(int i=0;i<a;i++){
    if(s[i]=='-') judge=false;
  }
  for(int i=a+1;i<a+b+1;i++){
    if(s[i]=='-') judge=false;
  }
  if(judge) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}