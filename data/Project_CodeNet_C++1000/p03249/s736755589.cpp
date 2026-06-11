#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define MaxN 100002
int n;
vector<long long >d;
vector<int>v[MaxN];
map<long long,int>mp;
int sz[MaxN];
bool vis[MaxN];
long long dp[MaxN];
int cnt[MaxN];
inline void dfs(int now,int par=-1){
    cnt[now]++;
    vis[now]=true;
    for(int go:v[now]){
        if(go == par)continue;
        if(vis[go]){
            printf("-1\n");
            exit(0);
        }
        dfs(go,now);
        dp[now] += dp[go] + cnt[go];
        cnt[now] += cnt[go];
    }
} 
long long int ans[MaxN];
inline void dfs2(int now,int par=-1,long long size = 0){
    ans[now] =dp[now]+size;
    size+=dp[now];
    for(int go:v[now]){
        if(go == par)continue;
        long long tmp = size - dp[go]-cnt[go]+(n-cnt[go]) ;
        dfs2(go,now,tmp);
    }
}
vector<pair<int,int>>ed;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    long long x;
    for(int i=0;i<n;i++){
        cin>>x;
        mp[x]=i;
        d.push_back(x);
    }
    for(auto it = mp.rbegin();it!=mp.rend();it++){
        int node = (*it).second;
        long long val = (*it).first;
        sz[node]++;
        long long op = n-sz[node];
        if(op==0)continue;
        long long nex = val + sz[node]- op;
        if(mp.count(nex)){
            int ne = mp[nex];
            sz[ne]+=sz[node];
            v[ne].push_back(node);
            v[node].push_back(ne);
            if(ne > node)swap(ne,node);
            ed.push_back(make_pair(ne+1,node+1));
        }
    }
    dfs(0);
    dfs2(0);
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            puts("-1");
            return 0;
        }
        if(ans[i]!=d[i]){
            puts("-1");
            return 0;
        }
    }
    for(int i = 0; i<ed.size();i++){
        cout<<ed[i].first<<' '<<ed[i].second<<endl;
    }
    return 0;
}