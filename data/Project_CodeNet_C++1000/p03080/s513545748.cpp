#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int red = 0;
    int blue = 0;
    rep(i,n) {
        if (s[i] == 'R') red++;
        else blue++;
    }
    string ans = "No";
    if (red > blue) ans = "Yes";
    cout << ans << endl;
}