#include<bits/stdc++.h>
using namespace std;
#define INFLL 1e17
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pr;

vector<vector<pair<int,ll>>>G;
vector<ll>dist;
// vの座標は事前に設定
void DFS(int v){
    for(auto &itr:G[v]){
    //    cout<<dist[itr.first]<<"=dist.    from "<<v<<" to "<<itr.first<<endl;
        if(dist[itr.first]!=-INFLL){
            if(dist[itr.first]!=dist[v]+itr.second){
                cout<<"No";
                exit(0);
            }
            continue;
        }
        dist[itr.first]=dist[v]+itr.second;
        DFS(itr.first);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    int l,r;
    ll d;
    cin>>n>>m;
    G=vector<vector<pair<int,ll>>>(n);
    dist=vector<ll>(n,-INFLL);
    for(int i=0;i<m;i++){
        cin>>l>>r>>d;
        G[l-1].push_back(make_pair(r-1,d));
        G[r-1].push_back(make_pair(l-1,-d));
    }
    for(int i=0;i<n;i++){
        if(dist[i]==-INFLL){
            dist[i]=0;
            DFS(i);
        }
    }
    cout<<"Yes";
    return 0;
}
