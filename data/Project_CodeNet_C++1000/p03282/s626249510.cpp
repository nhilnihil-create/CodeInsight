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

const int N = 1e5 + 5;
string s;
int k;

int main() {
    cin >> s >> k;
    int i = 0;
    while (k) {
        if (s[i] != '1') {
            cout << s[i] << endl;
            exit(0);
        }
        --k;
        ++i;
    }
    cout << '1' << endl;
    return 0;
}
