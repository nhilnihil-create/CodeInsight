#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int c1, c2;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t1, t2;
    cin >> s;
    for(int i = 0;i < s.size();++i)
    {
        if(i % 2)
        {
            t1 += '0';
            t2 += '1';
        }
        else
        {
            t1 += '1';
            t2 += '0';
        }
    }
    for(int i = 0;i < s.size();++i)
    {
        c1 += (t1[i] != s[i]);
        c2 += (t2[i] != s[i]);
    }
    cout << min(c1, c2);
    return 0;
}

