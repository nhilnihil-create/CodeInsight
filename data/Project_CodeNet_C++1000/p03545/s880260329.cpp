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
int n;
int a, b, c, d;
bool neg[3];

int main() {
    cin >> n;
    a = n / 1000;
    b = (n % 1000) / 100;
    c = (n % 100) / 10;
    d = n % 10;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                int t = a + b * (i ? 1 : -1) + c * (j ? 1 : -1) + d * (k ? 1 : -1);
                if (t == 7) {
                    char op1 = (i ? '+' : '-');
                    char op2 = (j ? '+' : '-');
                    char op3 = (k ? '+' : '-');
                    cout << a << op1 << b << op2 << c << op3 << d << "=7" << endl;
                    exit(0);
                }
            }
        }
    }
    return 0;
}
