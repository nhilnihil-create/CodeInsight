#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int n = s.length();

    map<char, int> M;
    rep(i, n)
    {
        M[s[i]]++;
    }

    //存在しないとき
    if (s == "zyxwvutsrqponmlkjihgfedcba")
    {
        cout << -1 << endl;
        return 0;
    }

    //付け加える形のとき
    for (int i = 97; i <= 122; i++)
    {
        char c = i;
        if (M[c] == 0)
        {
            s += c;
            cout << s << endl;
            return 0;
        }
    }

    //それ以外の形
    rep(j, n)
    {
        M[s[n - 1 - j]] = 0;
        char c1 = s[s.length() - 1];
        s = s.substr(0, s.length() - 1);
        for (int i = c1 + 1; i <= 122; i++)
        {
            char c2 = i;
            if (M[c2] == 0)
            {
                s += c2;
                cout << s << endl;
                return 0;
            }
        }
    }
}