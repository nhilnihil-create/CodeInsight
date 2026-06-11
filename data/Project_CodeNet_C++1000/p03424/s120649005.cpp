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
    set<char> se;

    rep(i, n)
    {
        char s;
        cin >> s;
        se.insert(s);
    }

    cout << ((se.size() == 4) ? "Four" : "Three") << '\n';

    return 0;
}
