#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_N = 100005;

ll distSum [MAX_N];
int subSize [MAX_N];

vector<int> adj [MAX_N];
void addEdge (int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void distSumDfs (int vertex, int parent, int source, int lvl, ll &ans) {
  ans += lvl;
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      distSumDfs(nxt, vertex, source, lvl + 1, ans);
    }
  }
}

int main () {
  int vertexc;
  cin >> vertexc;

  vector<pair<ll, int>> elems;
  map<ll, int> src;
  fill(subSize + 1, subSize + vertexc + 1, 1);
  for (int i = 1; i <= vertexc; i++) {
    cin >> distSum[i];
    
    src[distSum[i]] = i;    
    elems.push_back(make_pair(distSum[i], i));
  }

  sort(elems.begin(), elems.end(), greater<pair<ll, int>>());

  for (pair<ll, int> pr : elems) {
    if (pr == elems.back()) {
      break;
    }
    
    int vertex = pr.second;
    ll parentSum = distSum[vertex] + subSize[vertex] - (vertexc - subSize[vertex]);
    if (src.count(parentSum) == 0) {
      cout << -1 << endl;
      return 0;
    }

    int parent = src[parentSum];
    addEdge(vertex, parent);
    subSize[parent] += subSize[vertex];
  }

  ll realD = 0;
  distSumDfs(elems.back().second, -1, elems.back().second, 0, realD);
  if (realD != elems.back().first) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 1; i <= vertexc; i++) {
    for (int u : adj[i]) {
      if (u > i) {
        cout << i << " " << u << '\n';
      }
    }
  }
}
