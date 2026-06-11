#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, ss[303030][2];
string s;

int main()
{
    cin >> n >> s;
    rep(i, n)
    {
        if(s[i] == 'W')
        {
            ss[i][0]++;
        }
        ss[i + 1][0] = ss[i][0];
    }
    for (int i = n - 1; i > 0; i--)
    {
        if(s[i] == 'E')
        {
            ss[i][1]++;
        }
        ss[i - 1][1] = ss[i][1];
    }
    
    int res = min(ss[1][1], ss[n - 1][0]);
    for(int i = 1; i < n - 1; i++)
    {
        res = min(res, ss[i - 1][0] + ss[i + 1][1]);
    }
    cout << res << endl;
    
    return 0;
}