#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    rep(bit, 1 << n - 1)
    {
        int sum = s[0] - '0';
        vector<char> op(n - 1);
        rep(i, n - 1)
        {
            if (bit & (1 << i))
            {
                sum += s[i + 1] - '0';
                op[i] = '+';
            }
            else
            {
                sum -= s[i + 1] - '0';
                op[i] = '-';
            }
        }
        if (sum == 7)
        {
            int j = 1;
            rep(i, n - 1)
            {
                s.insert(s.begin() + j, op[i]);
                j += 2;
            }
            cout << s << "=7" << endl;
            break;
        }
    }
}
