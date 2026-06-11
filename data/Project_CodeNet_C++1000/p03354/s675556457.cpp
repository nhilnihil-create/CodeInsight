#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
#define ld long double
vector<int> F[100001];
int bel=0;
vector<int> belong[100001];
map<int,int> p;
bool visited[100001];
void dfs(int now,int c){
    int cn=0;
    if(!visited[now]){
        visited[now]=true;
        belong[c].push_back(now);
        p[now]=c;
        //keyは人、値は所属番号
        for(int j=0;j<F[now].size();j++){
            int child = F[now][j];
            if(!visited[child]){
                dfs(child,c);
                cn++;
            }
        }
        if(cn==0){
            bel++;
            //もう回り切った＝＞所属しているグループを変える
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),x(m),y(m);
    rep(i,n){
        cin>>a[i];
        a[i]--;
    }
    rep(i,m){
        cin>>x[i]>>y[i];
        x[i]--,y[i]--;
        F[x[i]].push_back(y[i]);
        F[y[i]].push_back(x[i]);
    }
    rep(i,n){
        visited[i]=false;
    }
    rep(i,n){
        dfs(i,bel);
    }
    int ans=0;
    rep(i,bel){
        set<int> s;
       // cout<<i<<"個目のグループ所属 ";
        rep(j,belong[i].size()){
            //cout<<belong[i][j]<<" ";
            s.insert(belong[i][j]);
        }
        rep(j,belong[i].size()){
            if(s.count(a[belong[i][j]]))ans++;
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
}