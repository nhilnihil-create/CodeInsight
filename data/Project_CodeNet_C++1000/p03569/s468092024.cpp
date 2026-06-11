#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  string s;
  cin >> s;
  ll k=s.size();
  ll l=0,r=k-1;
  ll cnt=0;
  while(r-l>0){
    if(s[l]==s[r]){
      r--;
      l++;
    }
    else if(s[r]=='x'&&s[l]!='x'){
      r--;
      cnt++;
    }
    else if(s[l]=='x'&&s[r]!='x'){
      l++;
      cnt++;
    }
    else{
      cnt=-1;
      break;
    }
  }
  cout << cnt << endl;
}