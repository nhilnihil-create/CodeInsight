#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int n,m,g[15][15],p[15],cnt[15];

int main()
{
    fastio();
    cin>>n>>m;
    rep(i,0,m-1){ int k,x;
        cin>>k;
        rep(j,1,k){
            cin>>x; g[--x][i] = 1;
        }
    }
    rep(i,0,m-1) cin>>p[i];
    int ans = 0;
    rep(i,0,(1<<n)-1){
        memset(cnt,0,sizeof(cnt));
        rep(j,0,n-1){
            if((i>>j)&1){
                rep(k,0,m-1){
                    if(g[j][k]) cnt[k]++;
                }
            }
        }
        int flag = 1;
        rep(i,0,m-1) if(cnt[i]%2 != p[i]) flag = 0;
        ans += flag;
    }cout<<ans<<endl;
    return 0;
}
