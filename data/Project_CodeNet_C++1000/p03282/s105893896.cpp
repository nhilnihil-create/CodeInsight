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



int main() {
    string  s;
    cin >> s;
    ll k;
    cin >> k;
    ll d = 0;
    while (s[d] == '1') {
        d++;
    }
    if (d >= k) {
        cout << 1 << endl;
        return 0;
    }
    else {
        cout << s[d] << endl;
    }
    return 0;
}