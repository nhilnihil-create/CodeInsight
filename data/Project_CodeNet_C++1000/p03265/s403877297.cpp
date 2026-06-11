#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int x3,y3,x4,y4;
    int len=0;

    int dx=x2-x1;
    int dy=y2-y1;

    x3=x2-dy;
    y3=y2+dx;
    x4=x3-dx;
    y4=y3-dy;

    printf("%d %d %d %d",x3,y3,x4,y4);
    

    return 0;
}
