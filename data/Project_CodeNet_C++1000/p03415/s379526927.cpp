#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    vector<string> c(3);
    rep(i, 3) cin >> c[i];

    rep(i, 3)
    {
        cout << c[i][i];
    }
    cout << endl;
    return (0);
}
