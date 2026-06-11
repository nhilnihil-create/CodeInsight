#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
    int A, B;
    cin >> A >> B;
    vector<string> ans(1);

    rep(i, A - 1)
    {
        if (ans.back().size() < 100)
        {
            ans.back() += ".#";
        }
        else
        {
            ans.push_back(string(100, '#'));
            ans.push_back(".#");
        }
    }
    ans.back() += string(100 - ans.back().size(), '#');
    ans.push_back(string(100, '#'));
    ans.push_back(string(100, '.'));

    if (B != 1)
    {
        ans.push_back(".#");
    }
    rep(i, B - 2)
    {
        if (ans.back().size() < 100)
        {
            ans.back() += ".#";
        }
        else
        {
            ans.push_back(string(100, '.'));
            ans.push_back(".#");
        }
    }
    ans.back() += string(100 - ans.back().size(), '.');

    int h, w;
    h = ans.size();
    w = 100;
    cout << h << " " << w << endl;
    rep(i, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}