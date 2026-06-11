#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    string s;
    cin >> s;
    rep(i, s.size() - 8)
    {
        cout << s[i];
    }
    cout << endl;
    // end

    return 0;
}
