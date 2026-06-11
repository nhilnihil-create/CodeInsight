#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> G;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G.push_back(make_pair(a, b));
    }

    sort(G.begin(), G.end(), [](const auto &a, const auto &b) {return a.second < b.second;});

    int cnt = 0;
    int tmp = -1;
    rep(i, M) {
        if (G[i].first >= tmp) {
            cnt++;
            tmp = G[i].second;
        }
    }
    cout << cnt << endl;
}