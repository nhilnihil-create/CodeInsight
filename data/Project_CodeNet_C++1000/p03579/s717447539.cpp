#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> to;
vector<int> color;

bool is_bipartite(int current, int now_color) {
	color[current] = now_color;
	for(auto&& next : to[current]) {
		if(color[next] == now_color) return false;
		else if(!color[next] && !is_bipartite(next, -now_color)) return false;
	}
	return true;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	to = vector<vector<int>>(n);
	color = vector<int>(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	bool frag = is_bipartite(0, 1);
	long long ans;
	if(frag) {
		long long b = count(color.begin(), color.end(), 1);
		long long w = count(color.begin(), color.end(), -1);
		ans = b * w - m;
	}
	else ans = n * (n - 1) / 2 - m;
	cout << ans << endl;
    return 0;
}
