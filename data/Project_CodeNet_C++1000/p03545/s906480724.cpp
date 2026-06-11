#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int N = s.size();
    vector<int> n(N);
    rep(i, N) n[i] = s[i] - '0';
    vector<string> op(3);
    rep(i, 1 << 3)
    {
        int sum = n[0];
        rep(j, 3)
        {
            if (i >> j & 1)
            {
                sum += n[j + 1];
                op[j] = '+';
            }
            else
            {
                sum -= n[j + 1];
                op[j] = '-';
            }
        }
        if (sum == 7)
        {
            cout << s[0] << op[0] << s[1] << op[1];
            cout << s[2] << op[2] << s[3] << "=7" << endl;
            return 0;
        }
    }
    return 0;
}