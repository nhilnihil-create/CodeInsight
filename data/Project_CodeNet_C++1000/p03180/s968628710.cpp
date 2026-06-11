#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

const int maxn = 17;
const int maxtot = 65536;

int n, v[maxn][maxn];
long long f[maxtot], g[maxtot];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }

    int tot = 1 << n;

    for (int i = 1; i < tot; ++i) {
        long long sum = 0;

        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                for (int k = j+1; k < n; ++k)
                    if (i & (1 << k))
                        sum += v[j][k];

        g[i] = sum;
    }

    for (int i = 1; i < tot; ++i) {
        int st = i & (-i);
        for (int j = st; j <= i; ++j)
            if ((j & i) == j) {
                f[i] = max(f[i], f[i-j] + g[j]);
            }
    }

    cout << f[tot-1] << endl;
	return 0;
}