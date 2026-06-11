#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
vector<int> F[100001];
int bel=0;
int dist[11][11]={};
//ワーシャルフロイド法
void warshal_froid(int n){
    rep(k,n){//kは中継点
    //すべての中継点kについて、iからkを通ってjに行く距離を調べている
        rep(i,n){
            rep(j,n){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    int h,w;
    cin>>h>>w;
    int c[10][10]={};
    rep(i,10){
        rep(j,10){
            if(i!=j){
                dist[i][j] = 1000000;
            }
        }
    }
    rep(i,10){
        rep(j,10){
            cin>>c[i][j];
            dist[i][j] = c[i][j];
        }
    }
    vector<vector<int>> a(h,vector<int> (w));
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
        }
    }
    warshal_froid(10);
    //iからjに変えるのに必要な魔力がc[i][j] => iからjへの距離がc[i][j] -> ワーシャルフロイドで最短距離を求める
    int ans=0;
    rep(i,h){
        rep(j,w){
            if(a[i][j]!=-1){
                ans += dist[a[i][j]][1];
            }
        }
    }
    cout<<ans<<endl;
}