#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    string ss, t;
    cin >> ss;
    cin >> t;
    bool check;
    vector<string> ans;
    rep(i, 0, ss.size() - t.size() + 1)
    {
        check = true;
        rep(j, 0, t.size())
        {
            if (ss[i + j] != '?' && ss[i + j] != t[j])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            string tmp = ss;
            rep(j, 0, t.size())
            {
                tmp[i + j] = t[j];
            }
            rep(k, 0, tmp.size())
            {
                if (tmp[k] == '?')
                    tmp[k] = 'a';
            }
            ans.push_back(tmp);
        }
    }
    if (!ans.size())
        cout << "UNRESTORABLE" << endl;
    else
    {
        string min = ans[0];
        rep(i, 0, ans.size())
        {
            min = ans[i] < min ? ans[i] : min;
        }
        cout << min << endl;
    }
}
int main()
{
    func();
}