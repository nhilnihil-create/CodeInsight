#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#define SF scanf
#define PF printf
#define MAXN 350
using namespace std;
typedef unsigned long long ll;
int n;
char s[MAXN];
map<pair<ll,ll> ,ll> used[MAXN][MAXN];
ll ans;
void dfs1(int x,ll sum1,ll sum2,int len1,int len2){
    if(x==n){
        used[len1][len2][make_pair(sum1,sum2)]++;
        return ;
    }
    dfs1(x+1,sum1*131+(ll)(s[x]-'a'+1),sum2,len1+1,len2);
    dfs1(x+1,sum1,sum2*131+(ll)(s[x]-'a'+1),len1,len2+1);
}
void dfs2(int x,ll sum1,ll sum2,int len1,int len2){
    if(x==n-1){
        ans+=used[len1][len2][make_pair(sum1,sum2)];
        return ;
    }
    dfs2(x-1,sum1*131+(ll)(s[x]-'a'+1),sum2,len1+1,len2);
    dfs2(x-1,sum1,sum2*131+(ll)(s[x]-'a'+1),len1,len2+1);
}
int main(){
    SF("%d",&n); 
    SF("%s",s);
    dfs1(0,0,0,0,0); 
    dfs2(2*n-1,0,0,0,0);
    PF("%llu",ans);
} 