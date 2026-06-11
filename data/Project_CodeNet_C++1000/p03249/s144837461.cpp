//Link : https://atcoder.jp/contests/arc101/tasks/arc101_c

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005

vector<int> adj[N];
ll d[N];
pair<ll,int> in[N];
int sz[N];

int dsz[N];
ll dd[N];

void dfs(int node) {
  dsz[node] = 1;
  for(int ch : adj[node]) {
    dfs(ch);
    dsz[node] += dsz[ch];
    dd[node] += dd[ch] + dsz[ch];
  }
}

bool dfs2(int node,ll tmp,int n) {
  if(tmp!=d[node]) {
    return false;
  }
  for(int ch : adj[node]) {
    if(!dfs2(ch,tmp + n - dsz[ch]*2,n)) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n;scanf("%d ", &n);
  set<pair<ll,int> >s;
  ll sum = 0;
  for(int i=1;i<=n;++i) {
    scanf("%lld ", &in[i].first);
    d[i] = in[i].first;
    in[i].second = i;
    sz[i] = 1;
    s.insert(in[i]);
    sum += d[i];
  }
  if(sum%2==1) {
    printf("-1\n");
    return;
  }
  sort(in+1,in+n+1);
  int pos = n;

  while(s.size()>1) {
    pair<ll,int> tmp = *prev(s.end());
    s.erase(prev(s.end()));
    ll dist = tmp.first;
    int node = tmp.second;
    pair<ll,int> tmp2 = make_pair(dist - n + sz[node]*2,0);
    set<pair<ll,int> >::iterator it = s.lower_bound(tmp2);
    if(it==s.end() || (*it).first!=tmp2.first) {
      printf("-1\n");
      return;
    }
    int x = (*it).second;
    sz[x] += sz[node];
    adj[x].push_back(node);
  }
  int root = in[1].second;
  dfs(root);
  if(!dfs2(root,dd[root],n)) {
    printf("-1\n" );
    return;
  }
  for(int i=1;i<=n;++i) {
    for(int ch : adj[i]) {
      printf("%d %d\n", i,ch);
    }
  }
}

int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
