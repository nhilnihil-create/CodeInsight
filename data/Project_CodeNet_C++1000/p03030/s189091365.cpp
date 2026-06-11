#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<string, int>;
using T = tuple<string, int, int>;

int main()
{
    int n;
    cin >> n;
    T q[n];
    rep(i, n)
    {
        string s;
        int x;
        cin >> s >> x;
        //pair,tpuleの初期化はmale_pair/make_tpuleがよい
        q[i] = make_tuple(s, -1 * x, i + 1);
    }
    sort(q, q + n);
    rep(i, n) cout << get<2>(q[i]) << endl;
}