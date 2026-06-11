#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>
using namespace std;
using Int = int64_t;
Int solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;
    if (accumulate(A.begin(), A.end(), (Int)0) < accumulate(B.begin(), B.end(), (Int)0)) return -1;
    vector<int> g, l;
    for (int i = 0; i < N; i++) {
        auto t = A[i] - B[i];
        if (t > 0) g.push_back(t);
        else if (t < 0) l.push_back(-t);
    }
    if (l.size() == 0) return 0;
    sort(g.begin(), g.end(), greater<int>());
    auto t = accumulate(l.begin(), l.end(), (Int)0);
    for (size_t i = 0; i < g.size(); i++) {
        t -= g[i];
        if (t <= 0) return l.size() + i + 1;
    }
    return -1;
}
int main() {
    cout << solve() << endl;
}