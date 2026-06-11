#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin >> h >> w;
    char c[h][w];
    REP(i,h){
        REP(j,w){
            cin >> c[i][j];
        }
    }
    REP(i,h){
        REP(j,w){
            if(c[i][j]=='.'){
                continue;
            }
            bool f=false;
            REP(k,4){
                int x=i+dx[k],y=j+dy[k];
                if(x>=0&&x<h&&y>=0&&y<w){
                    if(c[x][y]=='#'){
                        f=true;
                    }
                }
            }
            if(!f){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}