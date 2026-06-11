#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7;
// l, r, v
using Data = tuple<int, int, int>;
int main() {
    int N;
    cin >> N;
    vector<Data> data;
    data.emplace_back(0, 0, 0);
    int T = 0;
    {
        vector<int> t(N), v(N);
        for(int i = 0; i < N; i++) {
            cin >> t[i];
            t[i] *= 2;
        }
        for(int i = 0; i < N; i++) {
            cin >> v[i];
            v[i] *= 2;
        }
        for(int i = 0; i < N; i++) {
            data.emplace_back(T, T + t[i], v[i]);
            T += t[i];
        }
    }
    data.emplace_back(T, T, 0);
    vector<int> V(T + 1, INF);
    for(int j = 0; j <= T; j++) {
        for(int i = 0; i < N + 2; i++) {
            int l, r, v;
            tie(l, r, v) = data[i];
            if(j < l) {
                V[j] = min(V[j], v + l - j);
            } else if(r < j) {
                V[j] = min(V[j], v + j - r);
            } else {
                V[j] = min(V[j], v);
            }
        }
    }
    double ans = 0;
    for (int j = 0; j < T; j++) {
        ans += V[j] + V[j + 1];
    }
    cout << std::fixed << std::setprecision(6) << ans / 8 << endl;
    return 0;
}
