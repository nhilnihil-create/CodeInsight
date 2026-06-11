#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for (int i = (start); i < (int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;

struct Node {
    int value;
    vector<Node*> connects;
};

int N, M;

int main(void)
{
    cin >> N >> M;
    vector<int> P(N + 1);
    REP(i, 1, N + 1) cin >> P[i];

    int ans = 0;

    // グラフを作る
    vector<vector<int>> connects(N + 1);

    rep(i, M) {
        int x, y;
        cin >> x >> y;

        connects[x].push_back(y);
        connects[y].push_back(x);
    }

    vector<int> searched(N + 1);
    vector<int> c(N + 1);
    for (int i = 1; i <= N; ++i) {
        if (searched[i] != 0) continue;
        stack<int> S;
        set<int> idxs;

        idxs.insert(i);
        S.push(i);
        searched[i] = 1;

        while (!S.empty())
        {
            int s = S.top();
            bool found = false;
            for(int k = c[s]; k < connects[s].size(); ++k) {
                int connect = connects[s][k];
                if (searched[connect] == 0) {
                    searched[connect] = 1;
                    S.push(connect);
                    c[s] = k + 1;
                    idxs.insert(connect);

                    found = true;
                    break;
                }
            }

            if (!found) {
                searched[s] = 2;
                S.pop();
            }
        }

        for(auto& idx : idxs) {
            if (idxs.find(P[idx]) != idxs.end()) ans++;
        }

    }

    cout << ans << endl;

    return 0;
}