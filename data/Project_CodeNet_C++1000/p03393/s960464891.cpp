#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    string s;
    cin >> s;
    if(s.size() != 26){
        char c = 'a';
        for (char x = 'a'; x <= 'z'; x++)
        {
            bool flag = true;
            rep(i, s.size())
            {
                if (s[i] == x) flag= false;
            }
            if(flag){
                c = x;
                break;
            }
        }
        cout << s + c << endl;
    }
    else if (s == "zyxwvutsrqponmlkjihgfedcba")
    {
        cout << -1 << endl;
    }else
    {
        int x;
        vector<string> v;
        string t = s;
        for (int i = 25; i > 0; i--)
        {
            if(s[i] > s[i-1]){
                string t = s.substr(i, 26 - i);
                sort(t.begin(), t.end());
                auto it = upper_bound(t.begin(), t.end(), s[i - 1]);
                s[i-1] = *it;
                s = s.substr(0, i);
                break;
            }
        }
        cout << s << endl;
    }
}