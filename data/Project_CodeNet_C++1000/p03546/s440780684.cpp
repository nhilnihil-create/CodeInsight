#include<bits/stdc++.h>
using namespace std;
#define INF 1000000

int main()
{
    int H,W;cin >> H >> W;
    vector<vector<int>> magic(10,vector<int> (10,INF));
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            cin >> magic[i][j];
        }
    }
    for (int k=0;k<10;k++)
    {
        for (int i=0;i<10;i++)
        {
            for (int j=0;j<10;j++)
            {
                magic[i][j]=min(magic[i][j],magic[i][k]+magic[k][j]);
            }
        }
    }
    int a,ans=0;
    for (int i=0;i<H;i++)
    {
        for (int j=0;j<W;j++)
        {
            cin >> a;
            if (a!=-1) ans+=magic[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}