#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<set<pair<int,int64_t>>> G(N);
    rep(i,0,N-1){
        int u,v;
        int64_t w;
        cin>>u>>v>>w;

        G.at(u-1).emplace(v-1,w);
        G.at(v-1).emplace(u-1,w);
    }

    vector<int> Ans(N,-1);
    Ans.front()=0;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int n=q.front();
        q.pop();

        for(auto g:G.at(n)){
            if(Ans.at(g.first)<0){
                if(g.second%2) Ans.at(g.first)=(!Ans.at(n));
                else Ans.at(g.first)=Ans.at(n);

                q.push(g.first);
            }
        }
    }

    for(auto ans:Ans) cout<<ans<<endl;
}