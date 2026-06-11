#include <bits/stdc++.h>
using namespace std;

int c[3][3];
int d1[3][2];
int d2[3][2];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>c[i][j];

    bool ans=true;

    for(int i=0;i<3;i++)for(int j=0;j<2;j++)
    {
        d1[i][j]=c[i][j+1]-c[i][j];
        d2[i][j]=c[j+1][i]-c[j][i];
    }

    for(int i=0;i<2;i++)
    {
        ans&=d1[0][i]==d1[1][i]&&d1[1][i]==d1[2][i];
        ans&=d2[0][i]==d2[1][i]&&d2[1][i]==d2[2][i];
    }

    puts(ans?"Yes":"No");

    return 0;
}
