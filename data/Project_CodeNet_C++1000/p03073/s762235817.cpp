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

    int n = s.size();
    int c = 1;
    int cnt1 = 0;
    rep(i, n)
    {
        if (s[i] != c + '0')
        {
            cnt1++;
        }
        c = 1 - c;
    }
    int cnt0 = 0;
    c = 0;
    rep(i, n)
    {
        if (s[i] != c + '0')
        {
            cnt0++;
        }
        c = 1 - c;
    }
    cout << min(cnt1, cnt0) << '\n';
    return 0;
}
