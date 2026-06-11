#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

string dp[10100];
const string MINUSINF = "-";
// dp[i] := マッチ棒をi本使ってできる最大値

void chmaxS(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> match = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int a[m];
    rep (i, m) cin >> a[i];

    rep (i, 10100) dp[i] = MINUSINF;

    dp[0] = "";
    for (int i = 0; i <= n; i++) {
        if (dp[i] == MINUSINF) continue;
        for (auto x: a) chmaxS(dp[i + match[x]], dp[i] + (char)('0' + x));
    }

    cout << dp[n] << endl;
    return 0;
}