#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    
    vector<pair<int, int>> p;
    for (int i = 1; i <= N / 2; i++) {
        p.push_back({i, N - i + (N % 2 == 0)});
    }

    vector<pair<int, int>> ans;
    REP(i, 0, p.size() - 1) {
        ans.push_back({p[i].first, p[i + 1].first});
        ans.push_back({p[i].first, p[i + 1].second});
        ans.push_back({p[i].second, p[i + 1].first});
        ans.push_back({p[i].second, p[i + 1].second});
    }

    if (N % 2 == 1) {
        ans.push_back({p[0].first, N});
        ans.push_back({p[0].second, N});
        if (p.size() > 1) {
            ans.push_back({p.back().first, N});
            ans.push_back({p.back().second, N});
        }
    } else {
        if (p.size() > 2) {
            ans.push_back({p[0].first, p.back().first});
            ans.push_back({p[0].first, p.back().second});
            ans.push_back({p[0].second, p.back().first});
            ans.push_back({p[0].second, p.back().second});
        }
    }

    cout << ans.size() << endl;
    for (auto a : ans) cout << a.first << " " << a.second << endl;
    return 0;
}