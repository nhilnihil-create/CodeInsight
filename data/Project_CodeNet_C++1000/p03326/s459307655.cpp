#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int M;
    cin >> N >> M;
    long long v[N][3];
    for (int i = 0; i < N; ++i) cin >> v[i][0] >> v[i][1] >> v[i][2];

    long long ans = 0;
    for (int bit = 0; bit < (1 << 3); ++bit) {
        long long tmp[N];
        for (int i = 0; i < N; ++i) {
            tmp[i] = 0;
            for (int j = 0; j < 3; ++j) {
                if (bit & (1 << j)) {
                    tmp[i] += v[i][j];
                } else {
                    tmp[i] -= v[i][j];
                }
            }
        }
        sort(tmp, tmp + N, greater<>());
        long long sum = 0;
        for (int i = 0; i < M; ++i) {
            sum += tmp[i];
        }
        ans = max(ans, sum);
    }
    cout  << ans << endl;
}