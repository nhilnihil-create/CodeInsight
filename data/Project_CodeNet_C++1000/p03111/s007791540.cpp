#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int N, A, B, C;
vi ans;

void dfs(int i, int a, int b, int c, vi &l, int cost) {
    if (i == N) {
        if (!a || !b || !c) return;
        ans.push_back(abs(a - A) + abs(b - B) + abs(c - C) + cost);
        return;
    }
    dfs(i + 1, a, b, c, l, cost);
    dfs(i + 1, a + l.at(i), b, c, l, cost + (a ? 10 : 0));
    dfs(i + 1, a, b + l.at(i), c, l, cost + (b ? 10 : 0));
    dfs(i + 1, a, b, c + l.at(i), l, cost + (c ? 10 : 0));
}

int main() {
    cin >> N >> A >> B >> C;
    vi l(N);
    rep(i, N) { cin >> l.at(i); }
    dfs(0, 0, 0, 0, l, 0);
    cout << *min_element(all(ans)) << endl;
}
