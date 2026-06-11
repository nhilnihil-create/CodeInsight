#include<bits/stdc++.h>
using namespace std;
#define ll            long long
#define nl            "\n"
#define PB            push_back
#define fi            first
#define se            second
#define _SAD()        ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
#define SZ(s)         s.size()
#define SRT(x,y)      sort(x,x+y)
#define REV(a,b)      reverse(a,a+b)
#define VSRT(x)       sort(x.begin(),x.end())
#define VREV(x)       reverse(x.begin(),x.end())
const int N = 1e5+10;
int main()
{
    _SAD()
    int a[3],x;
    cin>>a[0]>>a[1]>>a[2];
    x=a[2];
    SRT(a,3);
    if(x==a[1])
    {
        cout<<"Yes"<<nl;
    }
    else
    {
        cout<<"No"<<nl;
    }
    return 0;
}
