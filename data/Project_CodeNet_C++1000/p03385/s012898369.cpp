#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    string s;
    cin >> s;

    int a[3] = {0};
    rep(i, 3) a[s[i] - 'a']++;

    rep(i, 3)
    {
        if (a[i] != 1)
        {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}
