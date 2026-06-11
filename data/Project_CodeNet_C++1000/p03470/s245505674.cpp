#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    set<int> s;
    int x;
    rep(i, n) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}