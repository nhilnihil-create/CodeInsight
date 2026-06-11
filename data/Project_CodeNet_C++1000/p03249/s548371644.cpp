#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("atcoder(distancesums2).in","r",stdin);
    // freopen("atcoder(distancesums2).out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long>d(n);
    vector<int>size(n,1);
    map<long long,int>mp;
    for(int i=0;i<n;i++){
        cin>>d[i];
        mp[d[i]]=i;
    }
    vector<pair<int,int> >res;
    for(int itt = 0;itt<n-1;itt++){
    auto it = mp.rbegin();
    int i = it -> second;
    long long need = d[i] - n + 2 * size[i];
    if(mp.find(need) == mp.end() || mp[need] == i){
        cout<<"-1"<<endl;
       return 0;
    }
    int j = mp[need];
    res.emplace_back(i,j);
    size[j]+=size[i];
    mp.erase(--mp.end());
}
    vector<long long>real_dist(n,-1);
    real_dist[0] = 0;
    vector<vector<int>  >g(n);
    for(auto &p:res){
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }
    vector<int>que(1,0);
    for(int b = 0 ;b < (int)que.size();b++){
        for(int j:g[que[b]]){
            if(real_dist[j]==-1){
                que.push_back(j);
                real_dist[j] = real_dist[que[b]]+1;
            }
        }
    }
    if(accumulate(real_dist.begin(),real_dist.end(),0LL)!=d[0]){
        cout<<"-1"<<endl;
        return 0;
    }
    for(auto &p:res){
        cout<<p.first + 1<<' '<<p.second+1<<endl;
    }
    return 0;
}