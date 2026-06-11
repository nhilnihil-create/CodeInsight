#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(a) putchar(a)
#define int long long
#define inf (1ll<<60)
inline int read()
{
    int x=0,f=1;
    char c=gc();
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-f;
        c=gc();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return x*f;
}
int Num[25];
inline void write(int x)
{
    if(!x) {pc('0');return;}
    if(x<0) x=-x,pc('-');
    int top=0;
    while(x) Num[++top]=x%10,x/=10;
    while(top) pc(Num[top--]+'0');
    return;
}
#define ma 100005
const int cost[15]={0,2,5,5,4,5,6,3,7,6};
const char nu[15]={'0','1','2','3','4','5','6','7','8','9'};
string dp[ma];
inline bool empty(string s){return !s.size();}
int us[ma];
inline bool cmp(int x,int y){return x>y;}
inline bool bet(string x,string y)
{
	if(x.size()==y.size()) return x>y;
	return x.size()>y.size();
}
signed main()
{
    int n=read(),m=read();
    for(int i=1;i<=m;i++) us[i]=read();
    sort(us+1,us+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        for(int j=cost[us[i]];j<=n;j++)
        {
        	if(empty(dp[j-cost[us[i]]])&&j^cost[us[i]]) continue;
            string nxt=dp[j-cost[us[i]]]+nu[us[i]];
            if(empty(dp[j])||bet(nxt,dp[j]))
                dp[j]=nxt;
        }
    }
//    for(int i=1;i<=n;i++)
//    	cout<<i<<' '<<dp[i]<<endl;
    cout<<dp[n];
}






