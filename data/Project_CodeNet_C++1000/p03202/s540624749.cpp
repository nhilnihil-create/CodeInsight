#include<bits/stdc++.h>
using namespace std;
#define MN 200000
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<pair<int,int>,int> s[MN+5];
int n,top,ans=1,a[MN+5];
bool Solve(int ans)
{
    s[top=1]=make_pair(make_pair(1,a[1]),1);int len=a[1];
    for(int i=2;i<=n;++i)
    {
        int x=a[i];
        if(x>len) s[++top]=make_pair(make_pair(len+1,x),1);
        else
        {
            while(s[top].first.first>x) --top;
            if(s[top].first.second>x) s[top].first.second=x;
            while(top)
            {
                if(s[top].second<ans) 
                {
                    int t=s[top].second,l=s[top].first.second;
                    if(s[top].first.first<s[top].first.second) --s[top].first.second;
                    else --top;
                    s[++top]=make_pair(make_pair(l,l),t+1);
                    if(l<x) s[++top]=make_pair(make_pair(l+1,x),1);
                    break;
                }
                else --top;
            }
            if(!top) return false;
            else if(s[top].first.second<x) ++top,s[top]=make_pair(make_pair(s[top-1].first.second+1,x),1);
        }
        len=x;
       // cout<<i<<" finish "<<endl;
       // for(int j=1;j<=top;++j) printf("%d %d %d\n",s[j].first.first,s[j].first.second,s[j].second);
    }
    return true;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int l=1,r=n,mid,res;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(Solve(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res;
    return 0;
}