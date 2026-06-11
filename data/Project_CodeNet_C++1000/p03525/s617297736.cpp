#include <bits/stdc++.h>

using namespace std;


#ifdef CLION

ifstream ifs("/home/kyuridenamida/CLionProjects/untitled4/input.txt");
#define cin ifs
#define scanf DONT_USE_SCANF
#endif

typedef long long ll;

bool dp_[2][1 << 24];

int main() {
    int n;
    cin >> n;
    int determined = 1;
    int cnt[13] = {};
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        cnt[v]++;
    }

    vector<int> V;
    for (int i = 0; i <= 12; i++) {
        if (i == 0 && cnt[i] >= 1) {
            cout << 0 << endl;
            return 0;
        } else if (cnt[i] >= 3) {
            cout << 0 << endl;
            return 0;
        } else if (cnt[i] >= 2) {
            determined = determined | (1 << i) | (1 << (24 - i));
        } else if (cnt[i] == 1) {
            V.push_back(i);
        }

    }
    bool *dp = dp_[0];
    bool *ndp = dp_[1];
    dp[0] = 1;
    for (int i = 0; i < V.size(); i++) {
        memset(ndp, 0, sizeof(dp_[0]));
        for (int j = (1 << 24) - 1; j >= 0; j--) {
            ndp[j | (1 << V[i])] |= dp[j];
            ndp[j | (1 << (24 - V[i]))] |= dp[j];
        }
        swap(ndp, dp);
    }


    int gans = 0;
    for (int i_ = 0; i_ < (1 << 24); i_++) {
        if (dp[i_]) {
            int i = i_ | determined;
            int ans = 1e9;
            for (int k = 0; k <= 24; k++) {
                for (int j = k + 1; j <= 24; j++) {
                    if ((i >> k & 1) && (i >> j & 1)) {
                        ans = min(ans, min(abs(k - j), 24 - abs(k - j)));
                    }
                }
            }
            gans = max(ans, gans);
        }
    }
    cout << gans << endl;
}

