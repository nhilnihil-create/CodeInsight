#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    if(a >= b && a >= c) {
        rep(i, k) {
            a *= 2;
        }
        cout << a + b + c << endl;
    }
    else if(b > a && b >= c) {
        rep(i, k) {
            b *= 2;
        }
        cout << a + b + c << endl;
    }
    else if (c > a && c > b) {
        rep(i, k) {
            c *= 2;
        }
        cout << a + b + c << endl;
    }
    return 0;
}