#include<bits/stdc++.h>
using namespace std;
#define ll            long long
#define nl            "\n"
#define PB            push_back
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
int maxn=1e5+10;
int main()
{
    _SAD()
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"Hello World"<<nl;
    }
    else
    {
        int x,y;
        cin>>x>>y;
        cout<<x+y<<nl;
    }
    return 0;
}

