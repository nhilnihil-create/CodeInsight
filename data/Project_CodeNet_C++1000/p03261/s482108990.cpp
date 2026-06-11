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
    vector<string> a(n);
    set<string> s;
    rep(i,n) {
        string w;
        cin >> w;
        if (s.count(w)) {
            cout << "No" << endl;
            return 0;
        }
        s.insert(w);
        a[i] = w;
    }
    for (int i = 0; i <= n-2; i++) {
        if (a[i].back() != a[i+1][0]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}