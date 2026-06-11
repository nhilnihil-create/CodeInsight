#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin>>s;
  map<char,int>m;
  for(auto it:s)m[it]++;
  bool ok;
  if(m['a']==m['b']&&m['b']==m['c'])ok=true;
  else if(m['a']==m['b']&&m['a']==m['c']-1)ok=true;
  else if(m['a']==m['b']&&m['a']==m['c']+1)ok=true;
  else if(m['b']==m['c']&&m['b']==m['a']-1)ok=true;
  else if(m['b']==m['c']&&m['b']==m['a']+1)ok=true;
  else if(m['c']==m['a']&&m['c']==m['b']-1)ok=true;
  else if(m['c']==m['a']&&m['c']==m['b']+1)ok=true;
  else ok=false;
  if(ok)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
