#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
using Grid = vector<vector<int>>;
using vi = vector<int>;

int main() {
    int N;
    cin >> N;
    vector<tuple<string, int, int>> t;
    t.reserve(N);
    rep(i, N) {
        string s;
        int p;
        cin >> s >> p;
        t.emplace_back(s, -p, i + 1);
    }
    sort(t.begin(), t.end());
    rep(i, N) cout << get<2>(t[i]) << endl;
}