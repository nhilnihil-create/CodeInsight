#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn 500010
#define mod 1000000007
int ans[maxn];
vector<int>b[maxn];
ll c[maxn];
bool cmp(ll p,ll q){
    return p>q;
}
ll sum=0;
int cnt=0;
void sol(int x,int f){
    ans[x]=c[cnt++];
    if(f!=0) sum+=ans[x];
    for(int i=0;i<b[x].size();i++){
        if(b[x][i]!=f){
            sol(b[x][i],x);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        b[x].push_back(y);
        b[y].push_back(x);
    }
    for(int i=0;i<n;i++) scanf("%lld",&c[i]);
    sort(c,c+n,cmp);
    sol(1,0);
    printf("%lld\n",sum);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}