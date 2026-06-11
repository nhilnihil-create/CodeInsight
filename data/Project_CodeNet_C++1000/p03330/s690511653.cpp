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
    static const int MAXN=520;
    static const int MAXC=35;
    int N,C;
    ll d[MAXC][MAXC];
    ll c[MAXN][MAXN];
    ll mcost[3][MAXC];
    void solve(){
        ios::sync_with_stdio(false); 
        cin.tie(0);
        cin>>N>>C;
        for(int u=1;u<=C;u++){
            for(int v=1;v<=C;v++){
                cin>>d[u][v];
            }
        }
        for(int u=1;u<=N;u++){
            for(int v=1;v<=N;v++){
                cin>>c[u][v];
            }
        }
        for(int u=1;u<=N;u++){
            for(int v=1;v<=N;v++){
                for(int w=1;w<=C;w++){
                    mcost[(u+v)%3][w]+=d[c[u][v]][w];
                }
            }
        }
        ll ans=1e18;
        for(int u=1;u<=C;u++){
            for(int v=1;v<=C;v++){
                for(int w=1;w<=C;w++){
                    if(u==v||v==w||u==w)continue;
                    ans=min(ans,mcost[0][u]
                    +mcost[1][v]+mcost[2][w]);
                }
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