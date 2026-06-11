#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const int maxn=3e3+5;
char s[maxn];
ll num[maxn][maxn],nxt[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=1;i<=n;i++)
        num[1][i]=1;
    for(int i=1;i<n;i++)
    {
        char c=s[i-1];
        for(int j=1;j<=n-i+1;j++)
        {
            if(c=='<')
            {
                nxt[1]=(nxt[1]+num[i][j])%mod;
                nxt[j]=(nxt[j]-num[i][j]+mod)%mod;
            }
            else
            {
                nxt[j]=(nxt[j]+num[i][j])%mod;
                nxt[n-i+1]=(nxt[n-i+1]-num[i][j]+mod)%mod;
            }
        }
        for(int j=1;j<=n-i;j++)
            num[i+1][j]=(num[i+1][j-1]+nxt[j])%mod;
        for(int j=1;j<=n;j++)
            nxt[j]=0;
    }
    printf("%lld\n",num[n][1]);
    return 0;
}
/*
 '<': dp(i,j)->dp(i+1,1~(j-1))
 '>': dp(i,j)->dp(i+1,j~(n-i))
4
<><
 
5
<<<<
 
20
>>>><>>><>><>>><<>>
 
2
<
 */
