#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    int ans = 1e8;
    for (int i = 1; i < n; ++i) {
        int a = i;
        int b = n - i;
        int keta_sum_a = 0;
        int keta_sum_b = 0;
        while(1) {
            if (a == 0) break;
            keta_sum_a += a % 10;
            a /= 10;
        }
        while(1) {
            if (b == 0) break;
            keta_sum_b += b % 10;
            b /= 10;
        }
        ans = min(ans, keta_sum_a + keta_sum_b);
    }
    cout << ans << endl;
    return 0;
}
