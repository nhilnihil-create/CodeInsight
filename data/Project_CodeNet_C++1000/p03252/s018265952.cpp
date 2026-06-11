#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s, t;
    cin >> s >> t;
    map<char, char> start, goal;
    rep(i, s.length())
    {
        if (start.count(s[i]) || goal.count(t[i]))
        {
            if (start[s[i]] != t[i] || goal[t[i]] != s[i])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        start[s[i]] = t[i];
        goal[t[i]] = s[i];
    }
    cout << "Yes" << endl;
}