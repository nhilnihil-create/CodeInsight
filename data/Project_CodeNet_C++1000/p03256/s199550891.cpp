#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;
string S;

vint G[222222];

int cntA[222222],cntB[222222];
bool used[222222];

signed main(){
    cin>>N>>M>>S;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    rep(v,N)for(auto u:G[v]){
        if(S[u]=='A')cntA[v]++;
        else cntB[v]++;
    }

    queue<int>que;
    rep(v,N)if(cntA[v]==0||cntB[v]==0){
        used[v]=true;
        que.push(v);
    }
    while(que.size()){
        int v=que.front();que.pop();
        for(auto u:G[v]){
            if(used[u])continue;
            if(S[v]=='A')cntA[u]--;
            else cntB[u]--;
            if(cntA[u]==0||cntB[u]==0){
                used[u]=true;
                que.push(u);
            }
        }
    }

    if(count(used,used+N,false)!=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
