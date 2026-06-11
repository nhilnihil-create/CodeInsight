#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n/i) ret.push_back(i);
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        auto tmp = divisor(i);
        if (tmp.size() == 8) {
            ans++;
        }
    }

    cout << ans << endl;

}
