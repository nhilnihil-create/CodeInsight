#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
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

    int A, B;
    cin >> A >> B;
    string s;
    cin >> s;

    bool ispostal = true;
    if (s[A] == '-')
    {
        rep(i, A)
        {
            if (!isdigit(s[i]))
            {
                ispostal = false;
                break;
            }
        }
        repm(i, A + 1, s.size())
        {
            if (!isdigit(s[i]))
            {
                ispostal = false;
                break;
            }
        }
    }
    else
        ispostal = false;

    if (ispostal)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}