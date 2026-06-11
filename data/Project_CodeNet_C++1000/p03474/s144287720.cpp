#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    if ((int)s.size() == a + b + 1)
    {
        for (int i = 0; i < a + b + 1;++i)
        {
            if(i==a)
            {
                if (s[i] != '-')
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
            else if (s[i] < '0' || s[i] > '9')
            {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}