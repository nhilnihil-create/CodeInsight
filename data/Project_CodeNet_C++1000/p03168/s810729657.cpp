#include <bits/stdc++.h>
using namespace std;

int vis[3002][3002];
double dp[3002][3002];
double p[3002];
int n;
double coin(int pos,int head)
{
    if(head<0)
        return 0;
    if(pos==0)
    {
        if(head==0)
            return 1;
        else
            return 0;
    }
    if(vis[pos][head])
        return dp[pos][head];
    vis[pos][head]=1;
    return dp[pos][head]=p[pos]*coin(pos-1,head-1)+(1-p[pos])*coin(pos-1,head);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    double tot=0;
    for(int head=0;head<=n;head++)
    {
        int tail=n-head;
        if(head>tail)
            tot+=coin(n,head);
    }
    printf("%.9lf\n",tot);
}
