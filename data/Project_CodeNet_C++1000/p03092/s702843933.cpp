#include<iostream>
using namespace std;
int n,A,B,cr,Poz[5005],x,i,j;
long long Dp[5005][5005],cost;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>A>>B;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        Poz[x]=i;
    }
    for(i=1; i<=n; i++)
    {
        cr=1-cr;
        for(j=0; j<=n; j++)
        {
            if(j<Poz[i])
                cost=B;
            if(j==Poz[i])
                cost=0;
            if(j>Poz[i])
                cost=A;
            if(j==0)
                Dp[cr][j]=cost+Dp[1-cr][j];
            else
                Dp[cr][j]=min(Dp[cr][j-1],cost+Dp[1-cr][j]);
        }
    }
	cout<<Dp[cr][n]<<"\n";
    return 0;
}
