#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int N; cin >> N;
    vector< pair<int, int> > R(N), B(N);
    for (int i = 0; i < N; i++) cin >> R[i].first >> R[i].second;
    for (int i = 0; i < N; i++) cin >> B[i].first >> B[i].second;
    sort(R.begin(), R.end());
    sort(B.begin(), B.end());
    int b = 0;
    int cnt = 0;
    int m, tmp;
    vector<int> check(N);
    while (b < N) {
        m = -1; tmp = -1;
        for (int i = 0; i < N; i++) {
            if (R[i].first < B[b].first && R[i].second < B[b].second) {
                if (check[i] == 0 && m < R[i].second) {
                    tmp = i; m = R[i].second;
                }
            }
        }
        if (tmp >= 0) {
            check[tmp] = 1;
            cnt++;
        }
        b++;
    }
    cout << cnt << endl;
}
