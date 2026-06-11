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
    string s;
    cin >> s;
    int a = 0, b = 0;
    rep(i,s.size()) {
        if (s[i] == '0') a++;
        else b++;
    }
    int ans = 2*min(a,b);
    cout << ans << endl;
    return 0;
}