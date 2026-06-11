#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> m(N);
    REP(i, N) {
        cin >> m[i];
        X -= m[i];
    }
    sort(ALL(m));
    cout << X / m[0] + N << "\n";
    return 0;
}
