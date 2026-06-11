#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    rep(i, n + 1)
    {
        string s = to_string(i);
        int tmp = 0, tmpp = 0;
        rep(j, s.size())
        {
            tmp *= 10;
            tmp += s[j] - '0';
            tmpp += s[j] - '0';
        }
        if (tmpp >= a && tmpp <= b)
        {
            sum += tmp;
        }
    }
    cout << sum << endl;
    return 0;
}