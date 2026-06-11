#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define maxn 100005

int out_degree[maxn],in_degree[maxn];

ll result, path[maxn];
vector<ll> edge[maxn];

ll dfs(ll from) {
	ll longest = 0;


	if (!out_degree[from]) {
		return 0;
	}

	if (path[from]) {
		return path[from];
	}


	for (auto each : edge[from]) {

		longest = max(longest, dfs(each) + 1);

	}

	return path[from] = longest;
}

int main()
{
	ll N, M, x, y;
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		out_degree[x]++;
		in_degree[y]++;
		edge[x].push_back(y);
	}
	for (int i = 0; i < N; ++i) {
		if (out_degree[i + 1] && !in_degree[i + 1]) {
			result = max(dfs(i + 1), result);
		}
	}
	cout << result << endl;
	return 0;
}
