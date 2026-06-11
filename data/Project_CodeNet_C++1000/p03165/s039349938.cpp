#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
string s , t;
int f[N][N];

void trace(int i , int j)
{
    if(i == 0 || j == 0)return;
    if(f[i][j] == f[i-1][j-1] + 1 && f[i-1][j] + 1 == f[i][j] && f[i][j-1] + 1 == f[i][j])
    {
        trace(i-1 , j-1);
        cout << s[i-1];
    }
    else
    {
        if(f[i][j] == f[i-1][j])trace(i-1 , j);
        else trace(i , j-1);
    }
}

int main()
{
    cin >> s >> t;
    f[0][0] = 0;
    f[0][1] = 0;
    f[1][0] = 0;
    for(int i = 1; i <= s.size(); ++i)
    {
        for(int j = 1; j <= t.size(); ++j)
        {
            if(s[i-1] == t[j-1])f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j] , f[i][j-1]);
        }
    }
    //cout << f[s.size()][t.size()];
    trace(s.size() , t.size());
    return 0;
}
