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

int gcd(int a, int b){
	return b != 0 ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
	return a*b / gcd(a, b);
}

#define N_MAX 200000
#define MOD 1000000007

int N, tail;
int C[N_MAX], Cx[N_MAX];
vector<int> table[N_MAX];
int nextindex[N_MAX];

lli memo[N_MAX];
lli func(int index)
{
	if (-1 == index){
		return 0;
	}
	if (tail - 1 == index){
		return 1;
	}

	if (-1 != memo[index]){
		return memo[index];
	}

	lli ret = 1;
	ret = (ret + func(index + 1) - 1) % MOD;
	ret = (ret + func(nextindex[index])) % MOD;

	return memo[index] = ret;
}

void solv()
{
	scanf("%d", &N);
	int cmax = 0;
	for (int i = 0; i < N; i++){
		scanf("%d", C + i);
		cmax = max(cmax, C[i]);
	}

	tail = 0;
	Cx[tail] = C[0]; tail++;
	for (int i = 1; i < N; i++){
		if (C[i - 1] == C[i]){
			continue;
		}
		Cx[tail] = C[i];
		tail++;
	}

	table[Cx[0] - 1].push_back(0);
	for (int i = 1; i < tail; i++){
		table[Cx[i] - 1].push_back(i);
	}

	fill(nextindex, nextindex + N, -1);
	for (int i = 0; i < cmax; i++){
		for (int j = 1; j < table[i].size(); j++){
			nextindex[table[i][j - 1]] = table[i][j];
		}
	}

	fill(memo, memo + N, -1);
	printf("%lld", func(0));

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