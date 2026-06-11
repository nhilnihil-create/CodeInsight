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
    int n,k=0,cnt=0,ans=0;
    string s,ss;
    cin>>n>>s;
   // bool f=false;
    for(int i=0;i<SZ(s);i++)
    {
        //bool fl=false;
        if(s[i]=='.')
        {
            cnt++;
        }
    }
    ans=cnt;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='#')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<nl;
    return 0;
}
