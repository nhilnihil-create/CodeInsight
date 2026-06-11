#include<iostream>
using namespace std;
const int N=2e5+10;
int n,Q;
char s[N],t[N],d[N];
int Drop(int x)
{
    for(int i=1;i<=Q;i++)
    {
        if(s[x]==t[i]) x+=(d[i]=='R')?1:-1;
        if(x>n) return -1;
        if(x<1) return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>Q;
    scanf("%s",s+1);
    for(int i=1;i<=Q;i++) cin>>t[i]>>d[i];
    int l=1,r=n,la=0,ra=n+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(Drop(mid)==1) la=mid,l=mid+1;
        else r=mid-1;
    }
    l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(Drop(mid)==-1) ra=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ra-la-1<<endl;
}