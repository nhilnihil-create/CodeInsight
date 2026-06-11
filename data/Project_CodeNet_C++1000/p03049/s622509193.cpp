#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  ll n;cin>>n;
  ll cnta =0,cntb =0,cntba =0, out=0;
  for(ll i=0;i<n;++i){
    string s;cin>>s;
    if(s[0]=='B'&&s[s.size()-1]=='A'){
      ++cntba;
    } else if(s[0]=='B'){
      ++cntb;
    } else if(s[s.size()-1]=='A') {
      ++cnta;
    }
    for(int j=0;j<s.size()-1;++j)if(s.substr(j,2) == "AB")++out;
  }
  out += max(0LL, cntba-1);
  if(cntba>0){
    if(cntb>0){
      ++out;
      --cntb;
    }
    if(cnta>0){
      ++out;
      --cnta;
    }
  }
  out += min(cnta,cntb);
  cout << out << endl;
  return 0;
}
