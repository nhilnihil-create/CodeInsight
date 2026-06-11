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
    static const int MAXN=60;
    int K,N;
    ll x[MAXN],y[MAXN];
    void solve(){
        cin>>N>>K;
        for(int u=0;u<N;u++)cin>>x[u]>>y[u];
        ll ans=-1;
        for(int u1=0;u1<N;u1++){
            for(int v1=0;v1<N;v1++){
                for(int u2=0;u2<N;u2++){
                    for(int v2=0;v2<N;v2++){
                        int x1=x[u1],y1=y[v1],
                        x2=x[u2],y2=y[v2];
                        int lx=min(x1,x2),rx=max(x1,x2),
                        uy=min(y1,y2),dy=max(y1,y2);
                        int cnt=0;
                        for(int u=0;u<N;u++){
                            if(lx<=x[u]&&x[u]<=rx&&uy<=y[u]&&dy>=y[u]){
                                cnt++;
                            }
                        }
                        if(cnt>=K){
                            if(ans==-1)ans=(ll)(rx-lx)*(dy-uy);
                            else ans=min(ans,(ll)(rx-lx)*(dy-uy));
                        }
                    }
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