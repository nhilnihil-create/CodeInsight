#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <sstream>

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define range(x) begin(x), end(x)

#define dump(x) cerr << #x << " : " << x << '\n'

#define pb push_back

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
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(1, 1));
	d[1] = 1;
	while(!pq.empty())
	{
		int v = pq.top().second;
		int c = pq.top().first;
		pq.pop();
		if(d[v] < c) continue;
		int ten = (v * 10) % K;
		if(d[ten] > c)
		{
			d[ten] = c;
			pq.push(P(c, ten));
		}
		int inc = (v + 1) % K;
		if(d[inc] > c + 1)
		{
			d[inc] = c + 1;
			pq.push(P(c + 1, inc));
		}
	}
	printf("%d\n", d[0]);

	return 0;
}
