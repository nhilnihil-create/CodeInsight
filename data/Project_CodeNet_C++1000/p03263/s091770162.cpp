#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define re register
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define per(i,n,m) for(int i=m;i>=n;i--)
#define rrep(i,m,n) for(register int i=m;i<=n;i++)
#define rper(i,n,m) for(register int i=m;i>=n;i--)
#define ull unsigned  long long
using namespace std;
const int INF =1e9+10;
const int N = 5e2 + 10;
int a[N][N];
int ans;
struct node{
    int x,y,x1,y1;
    void output(){
        printf("%d %d %d %d\n",x,y,x1,y1);
    }
};
vector<node> g;
signed main() {
    int h,w;
    si(h);
    si(w);
    rep(i,1,h){
        rep(j,1,w){
            si(a[i][j]);
        }
    }
    rep(i,1,h){
        rep(j,1,w-1){
            if(a[i][j]&1){
                g.push_back({i,j,i,j+1});
                ans++;
                a[i][j+1]++;
            }
        }
    }
    rep(i,1,h-1){
        if(a[i][w]&1){
            ans++;
            g.push_back({i,w,i+1,w});
            a[i+1][w]++;
        }
    }
    printf("%d\n",ans);
    for(auto i:g){
        i.output();
    }
    return 0;
}
