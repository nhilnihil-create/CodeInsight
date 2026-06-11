#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m,x=0,y=0,z=0;
    cin>>n>>m;
    x+=m/10000;
    m%=10000;
    y+=m/5000;
    m%=5000;
    z+=m/1000;
    m%=1000;
    if(x+y+z>n)
    {
        x=-1;
        y=-1;
        z=-1;
    }
    else
    {

        int cur=x+y+z;
        int need=n-cur;
        while(x && need/9)
        {
            int div=need/9;
            if(div)
            {
                int sub=min(x,div);
                x-=sub;
                z+=10*sub;
            }
            need=n-(x+y+z);
        }
        while(x && need/1)
        {
            int div=need/1;
            if(div)
            {
                int sub=min(x,div);
                x-=sub;
                y+=2*sub;
            }
            need=n-(x+y+z);
        }
        while(y && need/4)
        {
            int div=need/4;
            if(div)
            {
                int sub=min(y,div);
                y-=sub;
                z+=5*sub;
            }
            need=n-(x+y+z);
        }
        if(need!=0)
        {
            x=-1;
            y=-1;
            z=-1;
        }
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}
