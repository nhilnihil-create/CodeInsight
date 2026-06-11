#include <bits/stdc++.h>
using namespace std;

// const long long int MOD = 1000000007;
const int MOD = 1000000007;


int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> s(M, vector<int>(0));
    vector<int> k(M), p(M);
    for (int i = 0; i < M; i++) {
        cin >> k[i];
        vector<int> empty(k[i]);
        s[i]=(empty);
        for (int j = 0; j < k[i]; j++) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int tmp = 0; tmp < (1 << N); tmp++) {
        bitset<10> b(tmp);
        int a = 1;
        for (int i = 0; i < M; i++) {
            int judge = 0;
            for (int j = 0; j < k[i]; j++) {
                if (b.test(s[i][j])) {
                    judge++;
                }
            }
            if (judge%2 != p[i]) {
                a *= 0;
            }
        }
        if (a == 1) {
            ans++;
        }
    }
    cout << ans << endl;
}
