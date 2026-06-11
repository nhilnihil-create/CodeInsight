#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    s[k - 1] = s[k - 1] - 'A' + 'a';
    cout << s << '\n';
    return 0;
}
