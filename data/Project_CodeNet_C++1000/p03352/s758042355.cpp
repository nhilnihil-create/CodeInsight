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
    int x;
    cin >> x;
    if (x == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 2; i * i <= x; ++i) {
        int num = i;
        bool flg = false;
        while(1) {
            if (num * i > x) {
                if (flg) ans = max(ans, num);
                break;
            }
            num *= i;
            flg = true;
        }
    }
    cout << ans << endl;
    return 0;
}
