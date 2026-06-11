#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdint>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    string A, B, C;
    cin >> A >> B >> C;
    int res = 0;
    rep(i, N) {
        if(A[i] == B[i] && B[i] == C[i])
            continue;
        else if(A[i] != B[i] && B[i] != C[i] && A[i] != C[i]) {
            res += 2;
        } else {
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}