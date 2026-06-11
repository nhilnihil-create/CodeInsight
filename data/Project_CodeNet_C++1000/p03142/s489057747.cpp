#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

#define N_MAX 100001

vector<int> edge[N_MAX], revedge[N_MAX];
int visited[N_MAX];
int order[N_MAX],tail;

void dfs(int cur)
{
	if (0 != visited[cur]){
		return;
	}

	visited[cur] = 1;
	for (int i = 0; i < edge[cur].size(); i++)
	{
		dfs(edge[cur][i]);
	}

	order[cur] = tail;
	tail--;

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	int N, M; scanf("%d%d", &N, &M);

	for (int i = 0; i < N + M - 1; i++){
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		edge[a].push_back(b);
		revedge[b].push_back(a);
	}

	fill(visited, visited + N, 0);
	tail = N-1;
	for (int i = 0; i < N; i++){
		dfs(i);
	}

	for (int i = 0; i < N; i++){
		int index = -1, val = -1;
		for (int j = 0; j < revedge[i].size(); j++){
			if (order[revedge[i][j]] > val){
				val = order[revedge[i][j]];
				index = revedge[i][j];
			}
		}
		printf("%d\n", index + 1);
	}

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}