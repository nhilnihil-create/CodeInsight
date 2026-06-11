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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    bool flag = false;
    rep(i, n)
    {
        if (s[i] == t[0])
        {
            flag = true;
            int j = 1;
            int k = 1;
            while (k < n)
            {
                if (i + j == n)
                    j = -i;
                if (s[i + j] != t[k])
                {
                    flag = false;
                    break;
                }
                j++;
                k++;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        cout << "Yes"
             << "\n";
    else
    {
        cout << "No"
             << "\n";
    }

    return 0;
}