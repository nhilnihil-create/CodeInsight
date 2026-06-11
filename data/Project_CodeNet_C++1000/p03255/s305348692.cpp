#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> x(N);
    vector<long long> S(N+1, 0);
    for(int i=0; i<N; ++i) {
        cin >> x[i];
        S[i + 1] = S[i] + x[i];
    }

    long long res = -1;
    for(int k=1; k<=N; ++k) {
        long long tmp = (N + k) * X;
        for(int j=0; ; ++j) {
            if(N % k == 0 && j >= N / k) break;
            if(N % k != 0 && j > N / k) break;
            tmp += (2 * (j == 0 ? 2 : j+1) + 1) * (S[N - k * j] - S[max(N - k * (j + 1), 0)]);
        }
        if(tmp < 0) continue;
        if(res == -1) res = tmp;
        else res = min(res, tmp);
    }

    cout << res << endl;
}