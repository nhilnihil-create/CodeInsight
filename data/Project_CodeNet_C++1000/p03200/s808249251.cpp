#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

bool flg = true;
ll cnt = 0, bcnt = 0;

string s;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'W')
        {
            cnt += bcnt;
        }
        else
        {
            bcnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
