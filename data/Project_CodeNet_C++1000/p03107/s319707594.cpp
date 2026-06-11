#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

string s;
int main() {
    cin >> s;
    int cnt = 0;
    int n = s.length();
    for (auto c : s) {
        if (c == '1')
            ++cnt;
    }
    cout << min(cnt, n - cnt) * 2 << endl;
    return 0;
}
