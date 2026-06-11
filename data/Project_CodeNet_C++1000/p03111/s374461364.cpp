#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
int N, A, B, C;
int minCost = INF;
vector<int> l(MAX);
/* function */
int dfs(int cur, int a, int b, int c) {
    if (cur >= N)
        return min({a, b, c}) > 0 ? abs(a - A) + abs(b - B) + abs(c - C) - 30 : INF;
    int ret0 = dfs(cur + 1, a, b, c);
    int ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
    int ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
    int ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;
    return min({ret0, ret1, ret2, ret3});
}
/* main */
int main(){
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) cin >> l[i];

    cout << dfs(0, 0, 0, 0) << '\n';
}