#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    double ans = 0;
    rep(i,n) {
        double x;
        string u;
        cin >> x >> u;
        if (u == "JPY") ans += x;
        else ans += x*380000;
    }
    printf("%.10f\n", ans);
    return 0;
}