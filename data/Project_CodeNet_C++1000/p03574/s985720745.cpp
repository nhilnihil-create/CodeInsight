#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

str m[60];

pair<int,int> dir[8]=
{
    {-1,-1},
    { 0,-1},
    { 1,-1},
    {-1, 0},
    { 1, 0},
    {-1, 1},
    { 0, 1},
    { 1, 1}
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w;cin>>h>>w;

    ss maketop;
    for(int i=0;i<w+2;i++)maketop<<'.';

    str top=maketop.str();

    m[0]=top;

    for(int i=1;i<=h;i++)
    {
        str mid;
        cin>>mid;
        ss makemid;
        makemid<<'.'<<mid<<'.';
        m[i]=makemid.str();
    }

    m[h+1]=top;

    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)
    {
        if(m[i][j]=='#')continue;
        int cnt=0;
        for(int k=0;k<8;k++)if(m[i+dir[k].second][j+dir[k].first]=='#')cnt++;

        m[i][j]=cnt+'0';
    }

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cout<<m[i][j];
        }
        cout<<"\n";
    }

    return 0;
}
