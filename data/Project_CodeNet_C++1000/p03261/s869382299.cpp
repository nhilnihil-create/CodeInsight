#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n;
    bool ans = true;
    cin >> n;
    string before, now;
    set<string>dist;
    cin >> before;
    dist.insert(before);
    rep(i, n-1) {
        cin >> now;
        if (dist.count(now)) {
            ans = false;
            break;
        }
        if (before.back() != now[0]) {
            ans = false;
            break;
        }
        dist.insert(now);
        before = now;
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}