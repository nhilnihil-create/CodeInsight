#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using psi = pair<string, int>;
using vpsi = vector<psi>;
bool compare_psi(psi a, psi b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}
int main()
{
    int n;
    cin >> n;
    vpsi gb(n), cp(n);
    rep(i, n)
    {
        string s;
        int p;
        cin >> s >> p;
        gb[i] = make_pair(s, p);
        cp[i] = gb[i];
    }
    sort(cp.begin(), cp.end(), compare_psi);
    // rep(i, n)
    // {
    //     cout << cp[i].first << " " << cp[i].second << endl;
    // }
    rep(i, n)
    {
        rep(j, n)
        {
            if (cp[i] == gb[j])
                cout << j + 1 << endl;
        }
    }
}
