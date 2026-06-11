#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e5 + 5;
int sz[N];
vector<int> g[N];

ll dfs(int node, int h) {
	ll ans = h;
	for (int to : g[node]) {
		ans += dfs(to, h + 1);
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<ll, int> mp;

    for (int i = 0; i < n; i++) {
    	ll d;
    	cin >> d;
    	mp[d] = i;
    	sz[i] = 1;
    }

    while (!mp.empty()) {
    	ll x = mp.rbegin()->first;
    	int y = mp.rbegin()->second;

    	// cout << x + 2 * sz[y] - n << " " << y << "\n";

    	if (mp.size() == 1) {
    		break;
    	}

    	if (x + 2 * sz[y] - n >= x) {
    		cout << "-1";
    		return 0;
    	}

    	if (!mp.count(x + 2 * sz[y] - n)) {
    		cout << "-1";
    		return 0;
    	}

    	int z = mp[x + 2 * sz[y] - n];

    	sz[z] += sz[y];
    	g[z].push_back(y);

    	mp.erase(prev(mp.end()));
    }

    int rt = mp.begin()->second;

    if (dfs(rt, 0) != mp.begin()->first) {
    	cout << "-1";
    	return 0;
    }

    for (int i = 0; i < n; i++) {
    	for (int to : g[i]) {
    		cout << i + 1 << " " << to + 1 << "\n";
    	}
    }

    return 0;   
}