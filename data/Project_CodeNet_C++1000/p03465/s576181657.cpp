#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
bitset<4000005> dp;
int n;
int a[2005];
int main(){
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++)
        dp|=(dp<<a[i]);
    int ans=0;
    for(int i=1;i<=sum;i++)
        if(dp[i] && i>=(sum+1)/2){
            ans=i;
            break;
        }
    printf("%d\n",ans);
    return 0;
}
