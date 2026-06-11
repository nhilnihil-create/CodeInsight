#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;



























int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<P>> a(N + 1, vector<P> (0));
    for (long long i = 0; i < M; i++) {
        long long p, y;
        cin >> p >> y;
        a[p].push_back(P (y, i + 1));
    }

    for(int i = 1; i <= N; i++) {
        sort(a[i].begin(), a[i].end());
    }

    vector<long long> ans(M + 1);
    for(long long i = 1; i <= N; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            P q = a[i][j];
            ans[q.second] = i * 1000000 + j + 1;
        }
    }


    for(int i = 1; i <= M; i++) {
        int keta = 0;
        long long b = ans[i] / 1000000;
        while (b) {
            keta++;
            b /= 10;
        }
        for (int j = 0; j < 6 - keta; j++) {
            cout << 0;
        }
        cout << ans[i] << endl;
    }
}