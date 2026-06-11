#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
using namespace std;
int main(void)
{
  string s;
  cin >> s;
  int m[256];
  REP(i,26) m['a'+i]=(1<<i);
  int tmp=0;
  map<int,int> d;
  d[0]=0;
  for(auto i=s.begin();i!=s.end();++i){
    tmp=(tmp^m[*i]);
    d.count(tmp) ? 0 : d[tmp]=33554432;
    REP(j,26) if(d.count(tmp^(1<<j))) d[tmp]=min(d[tmp],d[tmp^(1<<j)]+1);
  }
  cout << max(1,d[tmp]) << endl;
  return 0;
}