#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<vector<pair<int, int> > > adj;
vector<int> processed;
vector<int> pos;
bool works = true;

void dfs(int curr) {
  processed[curr] = 0;
  for(int i = 0; i<adj[curr].size(); ++i) {
    if(processed[adj[curr][i].first] == -1) {
      pos[adj[curr][i].first] = pos[curr] + adj[curr][i].second;
      dfs(adj[curr][i].first);
    }
    else {
      if(pos[adj[curr][i].first] != pos[curr] + adj[curr][i].second) {
        works = false;
      }
    }
  }
  processed[curr] = 1;
}

int main() {
  int n, m; cin >> n >> m;
  UF uf(n);

  adj.resize(n);
  processed.assign(n, -1);
  pos.assign(n, 0);
  for(int i = 0; i<m; ++i) {
    int l, r, d; cin >> l >> r >> d;
    l--; r--;
    uf.join(l, r);
    adj[l].push_back(make_pair(r, d));
    adj[r].push_back(make_pair(l, -d));
  }

  for(int i = 0; i<n; ++i) {
    if(processed[i] == -1) {
      pos[i] = 0;
      dfs(i);
    }
  }
  if(works) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
