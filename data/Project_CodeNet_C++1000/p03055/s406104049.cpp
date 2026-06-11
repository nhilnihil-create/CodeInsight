#include <cstdio>
#include <cmath>

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>

#include <algorithm>

using namespace std;
vector<vector<int> > vv;
vector<int> v, dist;

int main(int argc, char *argv[]) {
  	
  	
  	int n;
  	cin>> n;
  	vv = vector<vector<int> >(n + 1, vector<int> (0));
  	v = vector<int> (n + 1, 0);
  	dist = vector<int> (n + 1, -1);
  	for (int i = 0; i < n - 1; i++) {
  		int a, b;
  		scanf("%d%d", &a, &b);
  		// cin >> a >> b;
  		vv[a].push_back(b);
  		vv[b].push_back(a);
  		v[a]++;
  		v[b]++;
  	}

  	int res = 0;
  	queue<int> q;
  	for (int i = 1; i <= n; i++) {
  		if (v[i] == 1) {
  			q.push(i);
  			dist[i] = 0;
  		}
  	}

  	while (q.size() > 0) {
  		queue<int> qq;
  		while (q.size() > 0) {
  			int t = q.front();
  			q.pop();
  			v[t] = 0;
  			for (int i = 0; i < vv[t].size(); i++) {
  				if (v[vv[t][i]] == 0)
  					continue;
  				v[vv[t][i]]--;
  				res = max(res, dist[vv[t][i]] + dist[t] + 1);
  				dist[vv[t][i]] = max(dist[vv[t][i]], dist[t] + 1);
  				if (v[vv[t][i]] == 1) {
  					qq.push(vv[t][i]);
  				}
  			}
  		}
  		q = qq;
  	}

  	// cout << res << endl;
  	if (res % 3 == 1)
  		cout << "Second" << endl;
  	else
  		cout << "First" << endl;
}