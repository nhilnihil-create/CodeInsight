#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;

int toidx(int c1, int c2, int c3) {return c1 + c2 * 301 + c3 * (301 * 301);}

int main() {
	int n;
    cin >> n;
    int c[3] = {0};
    rep(i, n) {
        int t;
        cin >> t;
        c[t-1]++;
    }
    int ci = toidx(c[0], c[1], c[2]);
    set<int> s{ci};
    vector<double> dp(301 * 301 * 301);
    dp[ci] = 1;
    double ans = 0;
    rep(_, c[0]+c[1]*2+c[2]*3) {
        set<int> nxt;
        for(int t: s) {
            double p = dp[t];
            int c1, c2, c3;
            c1 = t % 301;
            t /= 301;
            c2 = t % 301;
            c3 = t / 301;
            int c = c1 + c2 + c3;
            ans += p * double(n) / c;
            if (c1 > 0) {
                int u = toidx(c1-1, c2, c3);
                dp[u] += p * c1 / c;
                nxt.insert(u);
            }
            if (c2 > 0) {
                int u = toidx(c1+1, c2-1, c3);
                dp[u] += p * c2 / c;
                nxt.insert(u);
            }
            if (c3 > 0) {
                int u = toidx(c1, c2+1, c3-1);
                dp[u] += p * c3 / c;
                nxt.insert(u);
            }
        }
        s = move(nxt);
    }
    printf("%.16f\n", ans);
}