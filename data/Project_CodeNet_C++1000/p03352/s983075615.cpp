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
    int ans = 1;
    for (int i = 2; i <= 1000; ++i) {
        int num = i * i;
        while(1) {
            if (num > x) break;
            ans = max(ans, num);
            num = num * i;
        }
    }
    cout << ans << endl;
    return 0;
}
