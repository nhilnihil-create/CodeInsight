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

string s;
int a[3];
int main() {
    cin >> s;
    for (int i = 0; i < 3; ++i) {
        ++a[s[i] - 'a'];
    }
    if (a[0] == 1 && a[1] == 1 && a[2] == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
