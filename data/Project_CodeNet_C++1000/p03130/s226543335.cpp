#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    vector<int> c(4, 0);
    rep(i, 6) {
        int ab; cin >> ab;
        c[ab - 1]++;
    }
    cout << (find(c.begin(), c.end(), 3) == c.end() ? "YES" : "NO") << endl;
}
