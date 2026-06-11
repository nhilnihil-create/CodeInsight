#include<bits/stdc++.h>
using namespace std;
#define NL            "\n"
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
int main()
{
    _SAD()
    int a,b,c;
    cin>>a>>b>>c;
    if((a+b)>=c)
    {
        cout<<"Yes"<<NL;
    }
    else
    {
        cout<<"No"<<NL;
    }
    return 0;
}
