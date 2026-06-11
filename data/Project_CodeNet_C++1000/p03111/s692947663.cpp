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
int N;
int minCost = INF;
vector<int> length(MAX), group(MAX), use(MAX);
vector<int> target(3);
/* function */
void check(int n) {
    vector<int> L(3), cnt(3, 0);
    for (int i = 0; i < n; i++) {
        L[group[use[i]]] += length[use[i]];
        cnt[group[use[i]]]++;
    }
    bool can = true;
    for (int i = 0; i < 3; i++) if (cnt[i] == 0) can = false;
    if (!can) return;
    int cost = 0;
    sort(L.begin(), L.end());
    for (int i = 0; i < 3; i++) {
        cost += abs(target[i] - L[i]);
        cost += (cnt[i] - 1) * 10;
    }
    minCost = min(cost, minCost);
}
void rec(int n, int l) {
    if (n >= l) {
        check(l);
        return;
    }
    for (int i = 0; i < 3; i++) {
        group[use[n]] = i;
        rec(n + 1, l);
    }
}
/* main */
int main(){
    cin >> N;
    for (int i = 0; i < 3; i++) cin >> target[i];
    sort(target.begin(), target.end());
    for (int i = 0; i < N; i++) cin >> length[i];

    for (int b = 7; b < (1 << N); b++) {
        int l = 0;
        for (int i = 0; i < N; i++) if ((b >> i) & 1) use[l++] = i;
        if (l >= 3) rec(0, l);
    }
    cout << minCost << '\n';
}