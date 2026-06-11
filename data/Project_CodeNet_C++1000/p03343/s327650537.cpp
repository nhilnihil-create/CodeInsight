#include <bits/stdc++.h>
#include <math.h>
#include <chrono>
using namespace std;
#pragma GCC optimize("-O3")
#define endl "\n"
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fwd(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()
#define what(x) cerr << #x << " is " << x << endl;

vector<int> org;
vector<int> poczatki;
vector<vector<int>> D;
int n, k, q;

main()
{
    _upgrade;
    cin >> n >> k >> q;
    org.resize(n);
    rep(i, n) cin >> org[i];
    poczatki = org;
    poczatki.pb(-12);
    sort(all(poczatki));

    int ans = 2e9;
    for (int l : poczatki)
    {
        vector<int> X;
        rep(i, n)
        {
            if (org[i] <= l)
            {
                if (X.size() > 0)
                {
                    D.pb(X);
                    X.clear();
                }
            }
            else
                X.pb(org[i]);
        }

        if (X.size() > 0)
        {
            D.pb(X);
            X.clear();
        }

        for (auto &W : D)
        {
            sort(all(W));
            rep(j, k - 1)
            {
                if (W.empty())
                    break;
                W.pop_back();
            }
            for (int a : W)
                X.pb(a);
        }

        sort(all(X));

        if (X.size() >= q)
        {
            ans = min(ans, X[q - 1] - X[0]);
            //cerr << X[q - 1] << " " << X[0] << endl;
        }
        D.clear();
    }
    cout << ans << endl;
}