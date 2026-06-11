#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define N 305

int n;
double dp[N][N][N];

double solve(int one,int two,int three)
{
    if(!one && !two && !three) return 0;
    double &ret=dp[one][two][three];
    if(ret!=-1) return ret;
    double tot=one+two+three;
    ret=(n-tot)/tot;
    if(one) ret+=(one+one*solve(one-1,two,three))/tot;
    if(two) ret+=(two+two*solve(one+1,two-1,three))/tot;
    if(three) ret+=(three+three*solve(one,two+1,three-1))/tot;
    return ret;

}

int main()
{
    fastio;
    cin>>n;
    int one=0,two=0,three=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1) one++;
        if(x==2) two++;
        if(x==3) three++;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=n;k++) dp[i][j][k]=-1;
        }
    }
    cout<<setprecision(8)<<fixed<<solve(one,two,three)<<endl;

}
