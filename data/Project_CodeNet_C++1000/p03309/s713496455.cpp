#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;

const int INF = 1e18;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n)
    {
        cin >> A[i];
        A[i] -= i + 1;
    }

    sort(ALL(A));

    int b = A[(n - 1) / 2];

    int ans = 0;
    rep(i, n) ans += abs(A[i] - b);
    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
