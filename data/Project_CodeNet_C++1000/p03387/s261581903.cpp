#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const int M = 1000005;

int main()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    int sum = a[0] + a[1] + a[2];
    if(sum % 2 == 0) {
        if(a[2] % 2 == 0) {
            cout << (3 * a[2] - sum) / 2 << endl;
        }
        else {
            cout << (3 * a[2] + 3 - sum) / 2 << endl;
        }
    }
    else {
        if(a[2] % 2 == 1) {
            cout << (3 * a[2] - sum) / 2 << endl;
        }
        else {
            cout << (3 * a[2] + 3 - sum) / 2 << endl;
        }
    }
    return 0;
}
