#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 111;

int A[MAX];

int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	PII mx = MP(-INF, -INF);
	PII mn = MP(INF, INF);
	FOR (i, 0, n)
	{
		scanf("%d", &A[i]);
		mx = max(mx, MP(A[i], i));
		mn = min(mn, MP(A[i], i));
	}

	vector<PII> res;

	if (abs(mx.first) > abs(mn.first))
	{
		FOR (i, 0, n)
		{
			if (A[i] < 0)
			{
				A[i] += A[mx.second];
				res.PB(MP(mx.second, i));
			}
		}

		FOR (i, 1, n)
		{
			A[i] += A[i-1];
			res.PB(MP(i-1, i));
		}
	}
	else
	{
		FOR (i, 0, n)
		{
			if (A[i] > 0)
			{
				A[i] += A[mn.second];
				res.PB(MP(mn.second, i));
			}
		}

		RFOR(i, n-1, 0)
		{
			A[i] += A[i+1];
			res.PB(MP(i+1, i));
		}
	}

	printf("%d\n", SZ(res));
	FOR (i, 0, SZ(res))
	{
		printf("%d %d\n", res[i].first + 1, res[i].second + 1);
	}

	// FOR (i, 0, n)
	// {
	// 	cout<<A[i]<<' ';
	// }
	// cout<<endl;



}
