#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+7;
typedef long long ll;
const int mod = 998244353;
#define IO cin.tie(0,ios::sync_with_stdio(false);
#define pi acos(-1)
#define PII pair<ll,ll>
ll read(){ll c = getchar(),Nig = 1,x = 0;while(!isdigit(c) && c!='-')c = getchar();if(c == '-')Nig = -1,c = getchar();while(isdigit(c))x = ((x<<1) + (x<<3)) + (c^'0'),c = getchar();return Nig*x;}
#define read read()

int s[]={0,2,5,5,4,5,6,3,7,6},a[maxn],ans[maxn],n,m,dp[maxn];
int cmp(int a,int b){
    if(s[a]!=s[b]) return s[a]<s[b];
    return a>b;
}
 
int cmp1(int a,int b){
    return a>b;
}
 
int main(){
 
    n=read,m=read;
    for(int i=0;i<m;i++){
        a[i]=read;
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
 
    int vis[10]={0};
    for(int i=0;i<m;i++){
        for(int j=s[a[i]];j<=n;j++){
            dp[j]=max(dp[j],dp[j-s[a[i]]]+1);
        }
    }
 
    sort(a,a+m,cmp1);
    while(n){
        for(int i=0;i<m;i++){
            if(n>=s[a[i]] && dp[n-s[a[i]]]+1==dp[n]){
                putchar(a[i]+'0');
                n=n-s[a[i]];break;
            }
        }
    }
 
    puts("");
    return 0;
}