#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int s;
    cin >> s;
    vector<int> a(100000);
    a[0] = s;
    bool finish = false;
    repl(i, 1, 100000) {
        if(a[i - 1] % 2 == 0) a[i] = a[i - 1] / 2;
        else a[i] = a[i - 1] * 3 + 1;
        rep(j, i) {
            if(a[i] == a[j]) {
                cout << i + 1 << endl;
                finish = true;
                break;
            }
        }
        if(finish) break;
    }
    return 0;
}