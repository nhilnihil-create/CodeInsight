#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include<iomanip>

using namespace std;
#define     loop(n,i,a)     for(int i=a;i<n;i++)
#define     all(arr,n)      arr,arr+n
#define     allv(v)         (v).begin(),(v).end()
#define     rallv(v)        (v).rbegin(),(v).rend()
#define     m_p             make_pair
#define     ll              long long
#define     vi              vector<int>
#define     vll             vector<ll>
#define     sz(x)           (int)x.size()
#define     pb              push_back
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int N = 2e5 + 3;
int n, a[N], b[N], tmp[N], freq[28];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	int res = 0;
	for (int bit = 0; bit <= 28; ++bit) {
		int MOD = (1 << (bit + 1));
		for (int i = 0; i < n; ++i)
			tmp[i] = b[i] % MOD;
		sort(tmp, tmp + n);
//		for (int i = 0; i < n; ++i)
//			cout << tmp [i] << " ";
//		cout << endl;
//		cout << " -------------- " << endl << bit << ":" << endl;
		for (int i = 0; i < n; ++i) {
			int x = lower_bound(tmp, tmp + n, (1 << bit) - a[i] % MOD) - tmp;
			int y = upper_bound(tmp, tmp + n, MOD - 1 - a[i] % MOD) - tmp - 1;

			int v = lower_bound(tmp, tmp + n, (1 << bit) + MOD - a[i] % MOD) - tmp;
			int u = upper_bound(tmp, tmp + n, MOD + MOD - 1 - a[i] % MOD) - tmp - 1;

			freq[bit] += y - x + 1  + v - u + 1;
		}
		if (freq[bit] % 2)
			res |= (1 << bit);
	}
	printf("%d\n", res);
	return 0;
}

/*
1 2 3 4 5
1 2 3 4 5

11+? = 010
11+1 = 100

1 1
1 2
1 5
2 1
2 4
2 5
3 3
3 4
4 1
4 3
4 5
5 2
5 4

 */


