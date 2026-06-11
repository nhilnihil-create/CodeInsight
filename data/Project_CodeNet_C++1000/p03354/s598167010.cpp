#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m,ans=0;
  cin >> n >> m;
  vector<long> p(n);
  vector<long> x(m);
  vector<long> y(m);
  vector<vector<long>> aaa(n,vector<long>(0));
  vector<unordered_set<long>> a(n);
  vector<long> v(n,-1);
  for(long i=0;i<n;i++) cin >> p[i];
  for(long i=0;i<m;i++) cin >> x[i] >> y[i];

  for(long i=0;i<m;i++) {
    aaa[x[i]-1].push_back(y[i]-1);
    aaa[y[i]-1].push_back(x[i]-1);
  }

  for(long i=0;i<n;i++) {
    if(v[i]==-1) {
      queue<long> q;
      q.push(i);
      while(q.size()!=0) {
        a[i].insert(p[q.front()]-1);
        v[q.front()]=i;
        for(long j=0;j<aaa[q.front()].size();j++) {
          if(v[aaa[q.front()][j]]==-1) {
            q.push(aaa[q.front()][j]);
          }
        }
        q.pop();
      }
      if(a[i].count(i)) ans++;
    } else {
      if(a[v[i]].count(i)) ans++;
    }
  }
  cout << ans << endl;
}