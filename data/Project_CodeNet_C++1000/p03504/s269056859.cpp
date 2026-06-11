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
    int N,C;
    int s[MAXN];
    int t[MAXN];
    int c[MAXN];
    int tmp[2*MAXN];
    int r[2*MAXN];
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>N>>C;
        for(int u=0;u<N;u++){
            cin>>s[u]>>t[u]>>c[u];
        }
        for(int ch=1;ch<=C;ch++){
            memset(tmp,0,sizeof(tmp));
            for(int u=0;u<N;u++){
                if(c[u]==ch){
                    tmp[2*s[u]-1]++;
                    tmp[2*t[u]]--;
                }
            }
            for(int t=1;t<2*MAXN;t++){
                tmp[t]+=tmp[t-1];
            }
            for(int t=0;t<2*MAXN;t++){
                if(tmp[t])r[t]++;
            }
        }
        int ans=0;
        for(int t=0;t<2*MAXN;t++)ans=max(ans,r[t]);
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();   
}