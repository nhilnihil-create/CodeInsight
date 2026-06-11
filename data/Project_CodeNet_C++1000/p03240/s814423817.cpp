#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct Point
{
    int x,y;
    long h;
};
inline long cal_h(Point& p,int x,int y)
{
    return (abs(p.x-x)+abs(p.y-y)+p.h);
}
int main(int argc, const char** argv) 
{
    int X,Y,N,maxix=0,minmx=100,maxiy=0,minmy=100,m;
    int TX,TY;
    long H,bias=0;
    cin>>N;
    Point a[100];
    for(int i=0;i!=N;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].h;
        maxix=max(maxix,a[i].x);
        minmx=min(minmx,a[i].x);
        maxiy=max(maxiy,a[i].y);
        minmy=min(minmy,a[i].y);
        if(a[i].h!=0)
        {
            m=i;
        }
    }
    for(X=minmx;X<=maxix;X++)
    {
        for(Y=minmy;Y<=maxiy;Y++)
        {
            H=cal_h(a[m],X,Y);
            int state=1;
            for(int i=0;i!=N;i++)
            {
                if(a[i].h!=max(H-abs(a[i].x-X)-abs(a[i].y-Y),bias))
                {
                    state=0;
                    break;
                }
            }
            if(state)
            {
                TX=X,TY=Y;
                cout<<TX<<' '<<TY<<' '<<H;
                return 0;
            }
        }
    }
    return 1;
}