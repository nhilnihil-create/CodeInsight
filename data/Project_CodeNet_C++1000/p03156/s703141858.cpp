#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REP(a, b, m) for (ll a = (ll)(b); a < (ll)(m); a++)

int main()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<int> v(n);

    int c1=0, c2=0, c3=0;
    rep(i, n)
    {cin >>v[i];
        if (v[i] <= a)
        {
            c1++;
        }
        else if (v[i] > b)
        {
            c3++;
        }
        else
        {
            c2++;
        }
    }
    cout << min(c1, min(c2, c3)) << endl;
}