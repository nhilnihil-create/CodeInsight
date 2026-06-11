#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<int> a;
vector<int> b = {3, 5, 7};
ll n;

void dfs(ll x) {
    rep(i,3) {
        ll nx = x*10 + b[i];
        if (nx > n) continue;
        a.push_back(nx);
        dfs(nx);
    }
}

bool f(int x) {
    vector<int> c(8);
    while (x > 0) {
        c[x%10]++;
        x /= 10;
    }
    bool ok = true;
    if (!c[7]) ok = false;
    if (!c[5]) ok = false;
    if (!c[3]) ok = false;
    return ok;
}

int main() {
    cin >> n;
    dfs(0);
    int ans = 0;
    for (int x : a) {
        if (f(x)) ans++;
    }
    cout << ans << endl;
    return 0;
}