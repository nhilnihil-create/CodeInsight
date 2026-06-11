#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved

bool cmp(pair<long long,int>x1,pair<long long,int>x2){
    return x1.first<x2.first;
}
//ABC099 D
int main(){
    int n,c;
    cin>>n>>c;

    long long d[c+1][c+1];
    rep2(i,c)rep2(k,c)cin>>d[i][k];

    long long grid[n+1][n+1];

    rep2(i,n)rep2(k,n)cin>>grid[i][k];
    vector<pair<long long,int> > change_cost[3];
    //cnt[l][k]:=割ったあまりがlのマスを色kに変えるコストの合計
    long long cnt[3][31]={};

    rep2(i,n){
        rep2(k,n){
            int now=(i+k);
            int l=now%3;
            rep2(col,c)
            cnt[l][col]+=d[grid[i][k]][col];
        }
    }





    rep2(i,c){
        rep(l,3){
            change_cost[l].push_back(make_pair(cnt[l][i],i));
        }
    }

    rep(l,3){
        sort(change_cost[l].begin(),change_cost[l].end(),cmp);
    }
    long long ans=INF;
    
    rep(k,3){
        int one=change_cost[0][k].second;
        rep(l,3){
            if(one==change_cost[1][l].second)continue;
    
            int two=change_cost[1][l].second;
            rep(i,3){
                if(one==change_cost[2][i].second || two==change_cost[2][i].second){
                    continue;
                }
                int three=change_cost[2][i].second;
                long long total=change_cost[0][k].first+
                                change_cost[1][l].first+
                                change_cost[2][i].first;
                ans=min(ans,total);
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;

}
/*
2 3
0 1 1
1 0 1
1 4 0
1 2
3 3

3

4 3
0 12 71
81 0 53
14 92 0
1 1 2 1
2 1 1 2
2 2 1 3
1 1 2 2

428
*/
