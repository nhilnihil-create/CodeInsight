#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    set<int> st;
    for (int i = a; i <= min(b, a + k - 1); i++)
        st.insert(i);
    for (int i = b; i >= max(a, b - k + 1); i--)
        st.insert(i);
    for (auto i : st)
        cout << i << endl;
}

int main()
{
    solve();
    return 0;
}