#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> V(N);
    for (int i = 0; i < N; ++i) cin >> V[i];

    long long result = 0;
    for (int a = 0; a <= min(N, K); ++a) {
        for (int b = 0; a + b <= min(N, K); ++b) {
            vector<long long> out;
            for (int i = 0; i < a; ++i) out.push_back(V[i]);
            for (int i = 0; i < b; ++i) out.push_back(V[N-i-1]);
            sort(out.begin(), out.end());

            // 操作を行う
            long long sum = 0;
            for (auto v : out) sum += v;
            for (int i = 0; i < min(a + b, K - a - b); ++i) {
                if (out[i] >= 0) break;
                sum -= out[i]; // 詰める
            }
            result = max(result, sum);
        }
    }
    cout << result << endl;
}