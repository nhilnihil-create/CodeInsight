#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=1e5+10;
    int N,M;
    int p[MAXN];
    int fa[MAXN];
    void init(){
        for(int u=0;u<MAXN;u++)fa[u]=u;
    }
    int tfind(int root){
        if(fa[root]==root)return root;
        int x=tfind(fa[root]);
        fa[root]=x;
        return x;
    }
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>N>>M;
        init();
        for(int u=1;u<=N;u++)cin>>p[u];
        for(int u=1;u<=M;u++){
            int x,y;
            cin>>x>>y;
            if(x>y)swap(x,y);
            int rx=tfind(x)
            ,ry=tfind(y);
            if(rx!=ry)fa[ry]=rx;
        }
        for(int u=1;u<=N;u++){
            tfind(u);
        }
        map<int,set<int>>mp;
        for(int u=1;u<=N;u++){
            mp[fa[u]].insert(u);
        }
        int ans=0;
        for(const auto &pr:mp){
            set<int>tmp=pr.second;
            for(const auto &v:tmp){
                if(pr.second.count(p[v]))ans++;
            }
        }
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}