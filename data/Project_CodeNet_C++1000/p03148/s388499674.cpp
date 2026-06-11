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
#include<stack>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=1e5+10;
    int N,K;
    class Sushi{
    public:
        int t;
        ll d;
        Sushi(){}
        Sushi(int tt,ll dd):t(tt),d(dd){}
    };
    vector<Sushi>sushis;
    int vis[MAXN];
    static bool cmp(Sushi s1,Sushi s2){
        return s1.d>s2.d;
    }
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>N>>K;
        for(int u=0;u<N;u++){
            int t;
            ll d;
            cin>>t>>d;
            sushis.push_back(Sushi(t,d));
        }
        sort(sushis.begin(),sushis.end(),cmp);
        stack<ll>st;
        ll acc=0,ans=0;
        int cnt=0,ty=0;
        for(int u=0;u<N;u++){
            int t=sushis[u].t;
            ll d=sushis[u].d;
            if(cnt<K){
                if(vis[t]==0){
                    vis[t]=1;
                    ty++;
                }
                else st.push(d);
                acc+=d;
                cnt++;
                ans=max(ans,acc+(ll)ty*ty);
            }
            else {
                if(st.empty())break;
                if(vis[t])continue;
                //对重复的进行替换
                vis[t]=1;
                ty++;
                acc-=st.top();
                st.pop();
                acc+=d;
                ans=max(ans,acc+(ll)ty*ty);
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