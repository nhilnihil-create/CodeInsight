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
    int n,m,k;
    cin>>n>>m;
    rep(i,m){
        int a,b,z;
        cin>>a>>b>>z;
        a--,b--;
        F[a].push_back(b);
        F[b].push_back(a);
    }
    rep(i,n){
        visited[i]=false;
    }
    rep(i,n){
        dfs(i,bel);
    }
    //cout<<bel<<endl;
    int ans=0;
    rep(i,bel){
        if(belong[i].size()!=0){
            ans++;
        }
    }
    cout<<ans<<endl;
    /*
    rep(i,bel){
        cout<<i<<"個目のグループ所属 ";
        rep(j,belong[i].size()){
            cout<<belong[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    /*
    for(int i=1;i<=n;i++){
        int block=0;
        if(B[i].size()>=1){
            rep(j,B[i].size()){
                if(p[i]==p[B[i][j]]){
    
                    block++;
                }
            }
        }
        int bsize=belong[p[i]].size();
        int fsize=F[i].size();
        //cout<<bsize<<"-"<<fsize<<"-1-"<<block<<"=";
        cout<<bsize-fsize-1-block<<" ";
    }
    */
}
