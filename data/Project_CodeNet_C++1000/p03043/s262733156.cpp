#include <bits/stdc++.h>
using namespace std;

int main() {
        int N, K;
        cin >> N >> K;
        double x, ff = 0;
        //
        for (int i = 1; i <= N; i++) {
                x = 1.0;
                for (int v = i; v < K; v *= 2) {
                        x /= double(2.0);
                }
                ff += x / double(N);
        }
        cout << fixed << setprecision(12) << ff << endl;
        return 0;
}
