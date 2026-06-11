#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int num_visited=0;
vector<int> G[300000];
vector<int> C[300000];
int visit[300000] = {};
int cnt[300000]={};
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    map<pair<int,int>,int> p;
    rep(i,n-1){
        cin >> a[i]>>b[i]>>c[i];
        c[i] %=2;
        a[i]--,b[i]--;
        p[make_pair(a[i],b[i])] = c[i];
        p[make_pair(b[i],a[i])] = c[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    //SearchC(0);
    vector<int> ans(n);
    ans[0] = 1; //黒で塗る
    queue <pair<int,int>> q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int now = q.front().first;
        int color = q.front().second;
        visit[now] = 1;
        q.pop();
        rep(i,G[now].size()){
            int child = G[now][i];
            if(visit[child]){
                continue;
            }
            if(p[make_pair(now,child)]==0){
                q.push(make_pair(child,color));
                ans[child] = color;
            }
            else{
                //color = !color;
                q.push(make_pair(child,!color));
                ans[child] = !color;
            }
            //cout<<child+1<<"を"<<color<<"で塗った"<<endl;
        }
    }
    rep(i,n){
        cout<<ans[i]<<endl;
    }
}