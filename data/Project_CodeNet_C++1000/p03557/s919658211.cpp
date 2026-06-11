/*
    Problem 20
    https://atcoder.jp/contests/abc077/tasks/arc084_a
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
const int MAX = 1000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<int> a, b, c;
int n;
/* function */
int bin1(int x) {
    int ok = 0;
    int ng = n+2;
    // a[i] < x なる最大の i を探す
    // ok , ..., ng
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (a[mid] < x) ok = mid;
        else ng = mid;
    }
    return ok;
}
int bin2(int x) {
    int ok = n+1;
    int ng = -1;
    // x < c[i] なる最小の i を探す
    // ng , ..., ok
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (x < c[mid]) ok = mid;
        else ng = mid;
    }
    return ok;
}
/* main */
int main(){
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    a.push_back(-1), a.push_back(INF);
    c.push_back(-1), c.push_back(INF);
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        // 真ん中を決めて， (|a[i] < b[i]|) * (|b[i] < c[i]|)
        ans += (ll)bin1(b[i]) * (ll)(n+1 - bin2(b[i]));
    }
    cout << ans << '\n';
}