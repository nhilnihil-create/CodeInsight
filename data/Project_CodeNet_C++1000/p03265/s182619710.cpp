#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int func(int x)
{
    if(x%2==0)
    {
        return x/2;
    }
    else
    {
        return 3*x+1;
    }
}
int main()
{
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int d = x2-x1;
    int u = y2-y1;
    int x3 = x2-u;
    int y3 = y2+d;
    int x4 = x3-d;
    int y4 = y3-u;

    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;


    return 0;
}