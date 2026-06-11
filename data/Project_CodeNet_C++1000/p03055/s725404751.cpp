#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

using namespace std;

typedef long long int lli;

int gcd(int a, int b) {
	return b != 0 ? gcd(b, a%b) : a;
}
lli gcd(lli a, lli b) {
	return b != 0 ? gcd(b, a%b) : a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
lli lcm(lli a, lli b) {
	return a * b / gcd(a, b);
}

#define N_MAX 200000
#define MOD 1000000007

vector<int> edge[N_MAX];
vector<pair<int,int> > table;

int visit[N_MAX];
void dfs(int index,int depth)
{
	visit[index] = 1;

	bool leaf = true;
	for (int i = 0; i < edge[index].size(); i++) {
		if (0 == visit[edge[index][i]]) {
			leaf = false;
			dfs(edge[index][i], depth + 1);
		}
	}

	if (leaf) {
		table.push_back(make_pair(depth, index));
	}

	return;
}

void solv()
{
	int N; scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int s, t; scanf("%d%d", &s, &t);
		s--; t--;
		edge[s].push_back(t);
		edge[t].push_back(s);
	}

	fill(visit, visit + N, 0);
	dfs(0, 1);

	sort(table.begin(), table.end());

	int idx = table[table.size() - 1].second;
	fill(visit, visit + N, 0);
	table.clear();
	dfs(idx, 1);

	sort(table.begin(), table.end());

	int diam = table[table.size() - 1].first;
	if (2 == diam % 3) {
		printf("Second");
	}
	else {
		printf("First");
	}

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	solv();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}
