#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const ll MX = 1e18;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = 0;
    rep(i, n) sum += a[i];
    int mini = 100100;
    rep(i, n) {
        mini = min(abs(n * a[i] - sum), mini);
    }
    rep(i, n) {
        if(mini == abs(n * a[i] - sum)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}