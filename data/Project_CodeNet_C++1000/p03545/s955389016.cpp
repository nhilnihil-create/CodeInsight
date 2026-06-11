#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int p[8][3]={
    {0,0,0},
    {1,0,0},
    {0,1,0},
    {0,0,1},
    {1,1,0},
    {1,0,1},
    {0,1,1},
    {1,1,1},
};

char pc[2]={'+','-'};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;
    cin>>s;

    int a,b,c,d;
    a=s[0]-'0';
    b=s[1]-'0';
    c=s[2]-'0';
    d=s[3]-'0';

    for(int i=0;i<8;i++)
    {
        int n=a;
        if(p[i][0])n-=b;
        else n+=b;
        if(p[i][1])n-=c;
        else n+=c;
        if(p[i][2])n-=d;
        else n+=d;

        if(n==7)
        {
            cout<<a<<pc[p[i][0]]<<b<<pc[p[i][1]]<<c<<pc[p[i][2]]<<d<<"=7";
            break;
        }
    }

    return 0;
}
