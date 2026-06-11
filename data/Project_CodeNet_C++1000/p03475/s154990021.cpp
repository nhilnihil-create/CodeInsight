#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    vector<int> c(n-1), s(n-1), f(n-1);
    rep(i, n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i, n) {
        if (i==n-1) {
            cout << 0 << endl;
            continue;
        }
        int now = i;
        int time = 0;
        while (now<n-1) {
            int t = max(s[now], ((time-1)/f[now]+1)*f[now]);
            time = t + c[now];
            now++;
        }
        cout << time << endl;
    }

    return 0;
}
