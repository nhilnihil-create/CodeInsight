// 7/4
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    rep(i, N) cin >> V[i];

    int res = 0;

    vector<int> MV;

    for (int A = 0; A <= N; A++) {
        for (int B = 0; B <= N - A; B++) {
            int now = 0;

            int T = K - A - B;  // Through / 捨てる
            if (T < 0) continue;
            
            MV.clear();
            rep(i, A) {
                now += V[i];
                if (V[i] < 0) MV.push_back(V[i]);
            }
            rep(i, B) {
                now += V[N-1-i];
                if (V[N-1-i] < 0) MV.push_back(V[N-1-i]);
            }
            sort(MV.begin(), MV.end());

            int t = min(T, (int)MV.size());
            rep(i, t) now -= MV[i];

            res = max(res, now);
        }
    }
    
    cout << res << endl;
}