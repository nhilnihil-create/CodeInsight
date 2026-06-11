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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    rep(i,n) {
        a[i] = s[i] - '0';
    }
    int b = INF;
    int ans = 0;
    rep(i,n-2) {
        int now = a[i]*100 + a[i+1]*10 + a[i+2];
        if (b > abs(753-now)) {
            ans = now;
            b = abs(753-now);
        }
    }
    cout << b << endl;
    return 0;
}