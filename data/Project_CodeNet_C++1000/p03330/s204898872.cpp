#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int c[505][505];
int pre[3][30];

int main(){
    int n,C;
    cin>>n>>C;
    int d[C][C];
    rep(i,C) rep(j,C) cin>>d[i][j];

    vector<vector<int>> cnt(3);
    rep(i,n){
        rep(j,n){
            cin>>c[i][j];
            c[i][j]--;
        }
    }

    rep(col,C) rep(i,n) rep(j,n) pre[(i+j)%3][col]+=d[c[i][j]][col];

    int ans=INF;
    rep(i,C){
        rep(j,C){
            rep(k,C){
                if(i==j) continue;
                if(j==k) continue;
                if(k==i) continue;
                ans=min(ans,pre[0][i]+pre[1][j]+pre[2][k]);
            }
        }
    }

    cout<<ans<<endl;

}
