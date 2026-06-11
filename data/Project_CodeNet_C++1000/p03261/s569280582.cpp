#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<string> w(n);
    set<string> se;
    rep(i, n)
    {
        cin >> w[i];
        se.insert(w[i]);
    }

    if (n != se.size())
    {
        cout << "No" << '\n';
        return (0);
    }

    char c = w[0].back();
    rep(i, n - 1)
    {
        if (w[i + 1].front() != c)
        {
            cout << "No" << '\n';
            return (0);
        }
        c = w[i + 1].back();
    }

    cout << "Yes" << '\n';
    return 0;
}
