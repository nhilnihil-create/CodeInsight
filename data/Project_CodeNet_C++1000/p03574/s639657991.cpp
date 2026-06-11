#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    char c[h][w];
    rep(i,h)rep(j,w) cin>>c[i][j];
    vector<vector<int>> a(h,vector<int>(w,0));
    int roty[8]={1,1,0,-1,-1,-1,0,1},rotx[8]={0,1,1,1,0,-1,-1,-1};
    rep(i,h)rep(j,w){
        if(c[i][j]=='#'){
            a[i][j]=-1;
            continue;
        }
        rep(k,8){
            int ny=i+roty[k],nx=j+rotx[k];
            if(0>ny||ny>=h||0>nx||nx>=w)continue;
            if(c[ny][nx]=='#')a[i][j]++;
        }
    }
    rep(i,h){
        rep(j,w){
            if(a[i][j]==-1)cout<<"#";
            else cout<<a[i][j];
        }
        cout<<endl;
    }
}