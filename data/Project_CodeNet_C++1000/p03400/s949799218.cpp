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
    int n, d, x;
    cin >> n >> d >> x;
    int ans = 0;
    rep(i, n) {
        int a;
        cin >> a;
        int num = 1;
        int cnt = 0;
        while(1) {
            if (num > d) break;
            num += a;
            ++cnt;
        }
        //cout << cnt << endl;
        ans += cnt;
    }
    cout << ans + x << endl;
    return 0;
}
