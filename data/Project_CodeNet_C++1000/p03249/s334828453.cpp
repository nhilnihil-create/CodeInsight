#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,int>id;
int n;
ll d[101000];

#define pli pair<ll,int>
#define fi first
#define se second
priority_queue<pli>q;

int fa[101000], sz[101000]; ll sum[101000];

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>d[i]; id[d[i]]=i;
    }
    sort(d+1,d+n+1,greater<ll>());
    for (int i=1;i<=n;++i){
        sz[i]=1;
        while (q.size()&&q.top().fi==d[i]){
            fa[q.top().se]=i;
            sz[i]+=sz[q.top().se];
            sum[i]+=sum[q.top().se]+sz[q.top().se];
            q.pop();
        }
        q.push({d[i]-(n-sz[i]*2),i});
    }
    if (q.size()!=1||sum[n]!=d[n]){
        puts("-1");
        return 0;
    }
    for (int i=1;i<n;++i)
        printf("%d %d\n",id[d[i]],id[d[fa[i]]]);
}