#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> g[100005];

int ans[100005];
ll A;
int e[100005];
int maxe,s;
bool use[10005];
int a[10005];
int b[10005];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; i++) {

    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
    e[a[i]]++;
    e[b[i]]++;
  }

  for(int i = 0; i < n; i++) {
    if(maxe < e[i]) {
      maxe = e[i];
      s = i;
    }
  }
  
  vector<int> c(n);
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(c.begin(),c.end(),greater<int> ());

  queue<int> q;
  q.push(s);
  use[s] = true;
  int k = 0;
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    ans[v] = c[k++];
    for(int i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      if(!use[u]) {
	use[u] = true;
	q.push(u);
      }
    }
  }

  for(int i = 0; i < n - 1; i++) {
    A += min(ans[a[i]],ans[b[i]]);
  }
  cout << A << endl;

  for(int i = 0; i < n - 1; i++) {
    cout << ans[i] <<" ";
  }
  cout << ans[n-1] << endl;
}
  
