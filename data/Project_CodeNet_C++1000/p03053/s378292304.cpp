#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=998244353;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<vector<int>> b(h,vector<int>(w,-1));
    queue<P> q;
    vector<int> di={-1,0,1,0},dj={0,-1,0,1};
    rep(i,h) {
        rep(j,w) {
            if (a[i][j]=='#') {
                b[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()) {
        P pp=q.front();
        int i=pp.first,j=pp.second;
        q.pop();
        rep(k,4) {
            int ni=i+di[k],nj=j+dj[k];
            if (ni>=0 && ni<h && nj>=0 && nj<w) {
                if (b[ni][nj]<0) {
                    b[ni][nj]=b[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
    }
    int ans=0;
    rep(i,h) {
        rep(j,w) ans=max(ans,b[i][j]);
    }
    cout << ans << endl;

    return 0; 
}
