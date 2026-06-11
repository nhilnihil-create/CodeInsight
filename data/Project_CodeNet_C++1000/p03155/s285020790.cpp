#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define pb push_back

const int N = 1e2 + 10;

int n, row, col;

signed main()   {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> row >> col;
    cout << (n - row + 1) * (n - col + 1);
}
