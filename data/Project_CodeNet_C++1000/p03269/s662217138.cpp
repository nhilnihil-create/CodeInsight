#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18
#define p2(a) (1 << (a))

int main() {
    int L;
    cin >> L;
    int N = (int)log2(L) + 1;
    vector<tuple<int, int, int>> e;
    for (int i = 1; i < N; i++) {
        e.push_back(make_tuple(i, i + 1, p2(i - 1)));
        e.push_back(make_tuple(i, i + 1, 0));
    }
    for (int i = N - 1; i >= 0; i--) {
        if (L - p2(i - 1) >= p2(N - 1)) {
            e.push_back(make_tuple(i, N, L - p2(i - 1)));
            L -= p2(i - 1);
        }
    }
    cout << N << " " << e.size() << endl;
    for (const auto& t : e) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    return 0;
}