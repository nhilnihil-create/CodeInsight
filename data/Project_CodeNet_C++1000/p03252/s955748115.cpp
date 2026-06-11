#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)


int main() {
  string s,t;
  cin>>s>>t;
  int n=s.size();
  vector<ll> v(26,-1);
  vector<ll> r(26,-1);
bool ok=true;
  rep(i,n){
    int s1=s[i]-'a';
    int t1=t[i]-'a';
    if (v[s1]>=0) {
      if (v[s1]!=t1){
        ok=false;
        break;
      }
     }
     if (r[t1]>=0) {
       if (r[t1]!=s1){
         ok=false;
         break;
       }
      }
      v[s1]=t1;
      r[t1]=s1;
}
if (ok==true)cout<<"Yes";
else cout<<"No";
}
