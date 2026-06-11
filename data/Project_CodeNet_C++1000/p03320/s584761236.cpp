#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int S(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

vector<int> kouho;

signed main() {
    int K;
    cin >> K;
    int prev = 0, m = 1;
    rep(i, K) {
        int x1 = prev + m, x2 = prev + 10 * m;
        if (x1 * S(x2) <= x2 * S(x1)) {
            prev = x1;
        } else {
            prev = x2;
            m *= 10;
        }
        cout << prev << endl;
    }
}
