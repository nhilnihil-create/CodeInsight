//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

#define INF (1LL << 60)

Int R[5 << 10][5 << 10];
int C[5 << 10][5 << 10];

int main()
{
	int N;
	Int A, B;
	scanf("%d%lld%lld", &N, &A, &B);

	int i, j;
	VInt p(N);
	VInt q(N);
	FOR(i, 0, N)
	{
		scanf("%d", &p[i]);
		--p[i];
		q[p[i]] = i;
	}

	CLEAR(C, 0);
	FOR(i, 0, N)
		RFOR(j, i, 0)
		{
			C[i][j] = C[i][j + 1];
			if (q[j] > q[i]) ++C[i][j];
		}

	FOR(i, 0, N + 1)
		FOR(j, 0, N + 1)
		R[i][j] = INF;

	R[0][0] = 0;
	FOR(i, 0, N)
		FOR(j, 0, N + 1)
		if(R[i][j] != INF)
		{
			if(p[i] <= j)
			{
				R[i + 1][max(j, p[i] + 1)] = min(R[i + 1][max(j, p[i] + 1)], R[i][j]);
				continue;
			}

			R[i + 1][j] = min(R[i + 1][j], R[i][j] + A);
			R[i + 1][p[i] + 1] = min(R[i + 1][p[i] + 1], R[i][j] + B*C[p[i]][j]);
		}

	Int res = INF;
	FOR(i, 0, N + 1) res = min(res, R[N][i]);

	printf("%lld\n", res);
	return 0;
};
