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

const int maxn = 3002;
const int mo = 1e9 + 7;

string s;
int n, ans, f[maxn][maxn];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n >> s;

    f[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i-1] == '<') {
            for (int j = 1; j <= i; ++j)
                f[i][j] = (f[i][j-1] + f[i-1][j-1]) % mo;
        } else {
            for (int j = i-1; j >= 0; --j)
                f[i][j] = (f[i][j+1] + f[i-1][j]) % mo;
        }
    }

    for (int j = 0; j <= n; ++j)
        ans = (ans + f[n-1][j]) % mo;

    cout << ans << endl;
	return 0;
}