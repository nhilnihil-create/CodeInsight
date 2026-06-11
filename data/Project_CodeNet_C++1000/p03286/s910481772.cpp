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
    int n;
    cin >> n;
    string s;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (n != 1) {
        if (abs(n)%2 == 0) {
            s += '0';
            n /= -2;
        }
        else {
            s += '1';
            n = (n-1)/-2;
        }
    }
    s += '1';
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}