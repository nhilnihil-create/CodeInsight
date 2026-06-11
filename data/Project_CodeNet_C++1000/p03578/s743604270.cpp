#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<int, int> d;
    rep(i,n) {
        int x;
        cin >> x;
        d[x]++;
    }
    int m;
    cin >> m;
    map<int, int> t;
    rep(i,m) {
        int x;
        cin >> x;
        t[x]++;
    }
    string ans = "YES";
    for(auto itr = t.begin(); itr != t.end(); itr++) {
        if (itr->second > d[itr->first]) ans = "NO";
    }
    cout << ans << endl;
}