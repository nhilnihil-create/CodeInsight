#include <stdio.h>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

const int MX = 200005;

int A[MX];

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	sort(A+1, A+N+1);

	auto it = lower_bound(A+1, A+N, A[N] / 2);
	int v = A[1], w = A[N-1];
	if(it != A+N) w = *it;
	if(it != A+1) v = *(--it);
	if(A[N]/2 - v > w - A[N]/2-1) printf("%d %d\n", A[N], w);
	else printf("%d %d\n", A[N], v);
}
