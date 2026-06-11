#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main()
{
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  vector<vecint> g(n);
  vecint ca(n, 0);
  vecint cb(n, 0);
  for(auto&& i:irange(0,m)) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
    if (s[a] == 'A') {
      ++ca[b];
    } else {
      ++cb[b];
    }
    if (s[b] == 'A') {
      ++ca[a];
    } else {
      ++cb[a];
    }
  }
  queue<int> q;
  vector<bool> vis(n, false);
  for(auto&& i:irange(0,n)) {
    if (ca[i] == 0 || cb[i] == 0) {
      q.push(i);
      vis[i] = true;
    }
  }
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for(auto&& to:g[i]) {
      if (s[i] == 'A') {
        --ca[to];
        if (ca[to] == 0 && !vis[to]) {
          q.push(to);
          vis[to] = true;
        }
      } else {
        --cb[to];
        if (cb[to] == 0 && !vis[to]) {
          q.push(to);
          vis[to] = true;
        }
      }
    }
  }
  bool ok = false;
  for(auto&& i:irange(0,n)) {
    if (!vis[i]) ok = true;
  }
  if(ok) {
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
