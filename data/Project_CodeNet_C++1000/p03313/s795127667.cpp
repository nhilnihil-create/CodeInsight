#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;
typedef pair <int, int > ii;
using ll = long long;
const int MAX=(1<<19),inf=0x3f3f3f3f,mod=1e9+7;

int dp[MAX];
ii a[MAX];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("bao.inp","r",stdin);
    //freopen("ESCAPE.out","w",stdout);
    int n,x;
    cin>>n>>x;
    int M=(1<<n);
    a[0]=ii(x,0);
    dp[0]=x;
    for(int i=1;i<M;i++){
        cin>>x;
        dp[i]=dp[i-1];
        for(int j=0;j<n;j++)if(i&(1<<j)){
            //cout<<i<<' '<<(i^(1<<j))<<'\n';
            a[i]=max(a[i],a[i^(1<<j)]);
            dp[i]=max(dp[i],dp[i^(1<<j)]);
        }
        dp[i]=max(dp[i],a[i].X+x);
        for(int j=0;j<n;j++)if(a[i].Y&(1<<j)){
            dp[i]=max(dp[i],a[i^(1<<j)].X+a[i].X);
        }
        cout<<dp[i]<<'\n';
        a[i]=max(a[i],ii(x,i));
    }
}
