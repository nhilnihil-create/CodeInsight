#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <string.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
double PI = 3.1415926535897932;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;
int l[100000], r[100000];

int main() {
    cin >> n;
    rep(i,n) cin >> l[i] >> r[i];
    sort(l, l+n, greater<int>()); sort(r, r+n);

    ll ans1 = 0;
    ll pre = 0;
    rep(i,n) {
        if (l[i] < pre) break;
        ans1 += l[i] - pre;
        pre = l[i];
        if (pre < r[i]) break;
        ans1 += pre - r[i];
        pre = r[i];
    }
    ans1 += abs(pre);
    ll ans2 = 0;
    pre = 0;
    rep(i,n) {
        if (r[i] > pre) break;
        ans2 += pre - r[i];
        pre = r[i];
        if (pre > l[i]) break;
        ans2 += l[i] - pre;
        pre = l[i];
    }
    ans2 += abs(pre);
    cout << max(ans1, ans2) << endl;
}