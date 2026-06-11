#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int iinf = 1 << 29;
const ll linf = 1l << 61;

int K;
int d[100000]; //dp[i] : K で割った余りが i になる数の桁の総和の最小値
// (nk + i) * 10 = i * 10 (mod K)
// (nk + i) + 1 = i + 1 (mod K)
// dp[(i * 10) % K] = dp[i];
// dp[(i + 1) % K] = 1 + dp[i];
// nord : i -> (i * 10) % K : 0
//      : i -> (i + 1) % K : 1

int main(int argc, char* argv[])
{
	scanf("%d", &K);
	fill(d, d + K, iinf);
	typedef pair<int, int> P;
	deque<P> q;
	q.emplace_back(1, 1);
	d[1] = 1;
	while(!q.empty())
	{
		int v = q.front().second;
		int c = q.front().first;
		q.pop_front();
		if(d[v] < c) continue;
		int ten = (v * 10) % K;
		if(d[ten] > c)
		{
			d[ten] = c;
			q.emplace_front(c, ten);
		}
		int inc = (v + 1) % K;
		if(d[inc] > c + 1)
		{
			d[inc] = c + 1;
			q.emplace_back(c + 1, inc);
		}
	}
	printf("%d\n", d[0]);

	return 0;
}
