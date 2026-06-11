#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ld long double
#define mid (l+r)/2
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
const int maxn=100005;
char s[maxn];
int fa[maxn];
int now,tot;
void newfa()
{
    fa[now]=++tot;
    now=tot;
}
void newson()
{
    fa[++tot]=now;
}
int main()
{
    #ifdef local
    freopen("in.txt","r",stdin);
    #endif
    cin>>s+1;
    int n=strlen(s+1);
    bool f=1;
    f&=(s[1]=='1');
    f&=(s[n]=='0');
    for(int i=1;i<=n/2;i++)
        if(s[i]!=s[n-i])
            f=0;
    if(!f)
    {
        cout<<"-1\n";
        return 0;
    }
    now=tot=1;
    newfa();
    for(int i=2;i<=n-1;i++)
    {
        if(s[i]=='0') newson();
        else newfa();
    }
    for(int i=1;i<=n-1;i++) cout<<i<<' '<<fa[i]<<endl;
}
