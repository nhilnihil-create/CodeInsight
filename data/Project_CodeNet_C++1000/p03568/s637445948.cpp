#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int num = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if(a % 2 == 0) {
            num++;
        }
    }
    cout << pow(3, n) - pow(2, num) << endl;
    return 0;
}
