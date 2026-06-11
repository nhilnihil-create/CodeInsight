/*
    Problem 11
    https://atcoder.jp/contests/abc128/tasks/abc128_c
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> S(n); // switchとつながっているlightのlist
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int s; cin >> s;
            S[s - 1].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) cin >> p[i];

    int ans = 0;
    // bit exhausive search
    for (int b = 0; b < (1 << n); b++) {
        vector<int> cnt(m);  // 点灯Switchの個数
        for (int i = 0; i < n; i++)
            if ((b >> i) & 1)
                for (int s : S[i]) cnt[s]++;
        // Judge
        bool can = true;
        for (int j = 0; j < m; j++) if (cnt[j] % 2 != p[j]) can = false;
        if (can) ans++;
    }
    cout << ans << '\n';
}