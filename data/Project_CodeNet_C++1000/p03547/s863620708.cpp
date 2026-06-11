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

char a, b;
int main() {
    cin >> a >> b;
    if (a > b) {
        cout << '>' << endl;
    } else if (a < b) {
        cout << '<' << endl;
    } else {
        cout << '=' << endl;
    }
    return 0;
}
