#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef long long lint;

// ソート済みの配列 vs に対して, from 以上 to 未満の数値の数を求める
int calc(int from, int to, const vector<int>& vs) {
    auto start = lower_bound(vs.begin(), vs.end(), from);
    auto end = lower_bound(vs.begin(), vs.end(), to);
    return end - start;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    int ans = 0;
    for (int k = 0; k < 30; k++) {
        vector<int> as(N), bs(N);
        for (int i = 0; i < N; i++) {
            as[i] = A[i] % (1<<(k+1));
            bs[i] = B[i] % (1<<(k+1));
        }
        sort(bs.begin(), bs.end());
        lint cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += calc((1<<k) - as[i], 2 * (1<<k) - as[i], bs);
            if (k < 29) cnt += calc(3 * (1<<k) - as[i], 4 * (1<<k) - as[i], bs);
        }
        ans |= (cnt%2)<<k;
    }
    cout << ans << endl;
    return 0;
}