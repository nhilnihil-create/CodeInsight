#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> cntsum(n, 0);
    repl(i, 1, n) {
        if(s[i - 1] == 'A' && s[i] == 'C') {
            cntsum[i] = cntsum[i - 1] + 1;
        }
        else cntsum[i] = cntsum[i - 1];
    }
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << cntsum[r] - cntsum[l] << endl;
    }
    return 0;
}
