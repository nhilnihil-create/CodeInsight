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

    string s;
    cin >> s;
    int n = s.size();

    if (s.front() == 'A')
    {
        int countC = 0;
        int index = 0;
        rem(i, 2, n - 1)
        {
            if (s[i] == 'C')
            {
                index = i;
                countC++;
            }
        }

        if (countC == 1)
        {
            bool flag = true;
            rem(i, 1, n)
            {
                if (i == index)
                    continue;
                if (!islower(s[i]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "AC"
                     << "\n";
                return 0;
            }
        }
    }

    cout << "WA"
         << "\n";

    return 0;
}