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

    int n;
    cin >> n;
    vector<string> vs(n);

    rep(i, n) cin >> vs[i];

    bool flag = true;
    rem(i, 1, n)
    {
        // std::cout << std::endl;
        // std::cout << vs[i - 1] << " , " << vs[i] << std::endl
        //           << endl;
        if (vs[i - 1].back() != vs[i].front())
        {
            flag = false;
        }
        rep(j, i)
        {
            if (vs[i] == vs[j])
            {
                flag = false;
            }
        }
    }

    if (flag)
        cout << "Yes"
             << "\n";
    else

        cout << "No"
             << "\n";

    return 0;
}