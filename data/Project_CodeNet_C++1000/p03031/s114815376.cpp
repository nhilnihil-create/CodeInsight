#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> s[M];
    for (int i = 0; i < M; i++) {
        int k; cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; i++) cin >> p[i];

    int ans = 0;
    for (int bit = 0; bit < (1<<N); bit++) {
        int sum = 0;
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int j = 0; j < s[i].size(); j++) {
                if ((bit >> s[i][j]) & 1) cnt++;
            }
            if (cnt % 2 == p[i]) sum++;
        }
        if (sum == M) ans++;
    }
    cout << ans << endl;
    return 0;
}