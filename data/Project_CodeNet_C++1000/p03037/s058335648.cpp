// https://atcoder.jp/contests/abc127/tasks/abc127_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // [l,r]
    // (1-indexed)
    int l = 1;
    int r = n;
    for (int i = 0; i < m; i++)
    {
        int l_, r_;
        cin >> l_ >> r_;
        l = max(l, l_);
        r = min(r, r_);
    }

    cout << max(0, r - l + 1) << endl;
    return 0;
}
