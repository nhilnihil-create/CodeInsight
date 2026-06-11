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

#define N_MAX 50
#define MOD 1000000007

int N, K;
pair<int,int> table[N_MAX];

bool check(int a, int b)
{
	int left = min(table[a].first, table[b].first), right = max(table[a].first, table[b].first);
	int bottom = min(table[a].second, table[b].second), top = max(table[a].second, table[b].second);
	int cnt = 0;
	for (int i = 0; i < N; i++){
		if (left <= table[i].first && table[i].first <= right && bottom <= table[i].second && table[i].second <= top){
			cnt++;
		}
	}

	return cnt >= K;
}

lli rect(int a, int b)
{
	int left = min(table[a].first, table[b].first), right = max(table[a].first, table[b].first);
	int bottom = min(table[a].second, table[b].second), top = max(table[a].second, table[b].second);
	return (lli)(right - left)*(lli)(top - bottom);
}

void solv()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++){
		int x, y; scanf("%d%d", &x, &y);
		table[i] = make_pair(x, y);
	}

	lli ret = numeric_limits<lli>::max();
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			for (int k = 0; k < N; k++){
				for (int l = k + 1; l < N; l++){
					int left = min(table[i].first, table[j].first), right = max(table[i].first, table[j].first);
					int bottom = min(table[k].second, table[l].second), top = max(table[k].second, table[l].second);
					int cnt = 0;
					for (int i = 0; i < N; i++){
						if (left <= table[i].first && table[i].first <= right && bottom <= table[i].second && table[i].second <= top){
							cnt++;
						}
					}
					if (cnt >= K){
						ret = min(ret, (lli)(right - left)*(lli)(top - bottom));
					}
				}
			}
		}
	}

	printf("%lld\n", ret);

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