#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Int = int64_t;
Int solve() {
    Int N, sumA = 0, sumB = 0;
    cin >> N;
    vector<Int> A(N), B(N);
    for (auto& i : A) {
        cin >> i;
        sumA += i;
    }
    for (auto& i : B) {
        cin >> i;
        sumB += i;
    }
    if (sumA < sumB) return -1;
    vector<Int> g;
    Int l = 0, cnt = 0;
    for (Int i = 0; i < N; i++) {
        auto t = A[i] - B[i];
        if (t > 0) g.push_back(t);
        else if (t < 0) {
            l += -t;
            cnt++;
        }
    }
    if (l == 0) return 0;
    sort(g.begin(), g.end(), greater<Int>());
    for (size_t i = 0; i < g.size(); i++) {
        if ((l -= g[i]) <= 0) return cnt + i + 1;
    }
    return -1;
}
int main() {
    cout << solve() << endl;
}