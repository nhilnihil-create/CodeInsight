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
    rep(i,3) {
        if (s[i] == '1') s[i] = '9';
        else s[i] = '1';
    }
    cout << s << endl;
    return 0;
}