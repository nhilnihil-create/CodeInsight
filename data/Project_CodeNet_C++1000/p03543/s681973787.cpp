#include<bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
//using namespace atcoder;

const ll mod=1000000007;//998244353;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  string s;
  cin >> s;
  bool ok=0;
  if(s[0]==s[1] && s[1]==s[2])ok=1;
  if(s[1]==s[2] && s[2]==s[3])ok=1;

  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}