#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int a, b, ans;
bool check(int x) {
    string s = to_string(x);
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        ++i;
        --j;
    }
    return true;
}
int main() {
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (check(i))
            ++ans;
    }
    cout << ans << endl;
    return 0;
}
