#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 30) - 1;

int main()
{
    string s;
    cin >> s;
    const int n = s.length();

    map<char, bool> f;

    vector<long long> mask(n);

    for (int i = 0; i < n; ++i) {
        f[s[i]] ^= 1;

        long long &now = mask[i];
        for (int j = 'a'; j <= 'z'; ++j) {
            now += (1 << (j - 'a')) * f[j];
        }
    }

    vector<int> DP(n, INF);

    map<long long, int> best_for_mask;

    auto update_for_i = [&] (int i)
    {
        if (!best_for_mask.count(mask[i]) ||
                best_for_mask[mask[i]] > DP[i]) {
            best_for_mask[mask[i]] = DP[i];
        }
    };
    best_for_mask[0] = 0;

    for (int i = 0; i < n; ++i) {

        int best = INF;
        auto check_cand = [&] (long long cand)
        {
            auto it = best_for_mask.find(cand);
            if (it == best_for_mask.end()) {
                return;
            }
            int now = it->second;
            if (now < best) {
                best = now;
            }
        };

        check_cand(mask[i]);
        for (int j = 'a'; j <= 'z'; ++j) {
            long long cand = mask[i] ^ (1 << (j - 'a'));
            check_cand(cand);
        }

        if (best == INF) {
            continue;
        }

        DP[i] = 1 + best;
        update_for_i(i);
    }

    cout << DP[n - 1] << "\n";
    return 0;
}
