#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n+1, 0);
    for(int i=0;i<n;++i) {
        a[i+1] = a[i];
        if(s[i] == '#') ++a[i+1];
    }

    int ans = n-a[n];
    for(int i=1;i<=n;++i) {
        int tmp = a[i] + (n-i - (a[n] - a[i]));
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}