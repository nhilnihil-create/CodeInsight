#include <random>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    vector<int> X, Y;
    int N, K;
    cin >> N >> K;
    vector<pair<int, int> > P;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
        P.emplace_back(x, y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    long long ans = 7e18;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = k + 1; l < N; l++) {
                    int cnt = 0;
                    for (int m = 0; m < N; m++) {
                        cnt += X[i] <= P[m].first && P[m].first <= X[j] &&
                               Y[k] <= P[m].second && P[m].second <= Y[l];
                    }
                    if (cnt >= K) {
                        ans = min(ans, 1ll * (X[j] - X[i]) * (Y[l] - Y[k]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}