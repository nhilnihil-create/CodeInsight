#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define EPS (1e-15)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define bet(x, a, b) (a) <= (x) && (x) < (b)
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	int N, A, B, P, cnt[3] = { 0, 0, 0 };

	cin >> N >> A >> B;
	rep(i, N) {
		cin >> P;
		if (P <= A) cnt[0]++;
		else if (P <= B) cnt[1]++;
		else cnt[2]++;
	}

	cout << min(cnt[0], min(cnt[1], cnt[2])) << endl;

	return 0;
}
