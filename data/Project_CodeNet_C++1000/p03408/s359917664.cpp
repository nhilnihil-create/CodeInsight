#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool compare(const pair<string, int> &x, const pair<string, int> &y)
{
    return x.second > y.second;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<string, int> > p;
    rep(i, n)
    {
        string s;
        cin >> s;

        bool flag = true;
        for (auto &e : p)
        {
            if (s == e.first)
            {
                e.second++;
                flag = false;
                break;
            }
        }
        if (flag)
            p.push_back(make_pair(s, 1));
    }
    int m;
    cin >> m;
    rep(i, m)
    {
        string s;
        cin >> s;

        bool flag = true;
        for (auto &e : p)
        {
            if (s == e.first)
            {
                e.second--;
                flag = false;
                break;
            }
        }
        if (flag)
            p.push_back(make_pair(s, -1));
    }

    sort(p.begin(),
         p.end(),
         compare);

    cout << max(0, p[0].second) << "\n";

    return 0;
}