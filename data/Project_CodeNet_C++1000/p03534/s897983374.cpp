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
  if((m['a']==m['b']&&m['b']==m['c']&&s.size()%3==0)||
      (m['a']-1==m['b']&&m['b']==m['c'])||
      (m['b']-1==m['c']&&m['c']==m['a'])||
      (m['c']-1==m['a']&&m['a']==m['b'])||
      (m['a']+1==m['b']&&m['b']==m['c'])||
      (m['b']+1==m['c']&&m['c']==m['a'])||
      (m['c']+1==m['a']&&m['a']==m['b'])
      )cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
