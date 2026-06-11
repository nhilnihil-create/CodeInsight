#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int x[505][505],a[100010],b[100010];

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    rep(i,m){
        int l,r;
        cin>>l>>r;
        x[l][r]++;
    }
    for(int i=1; i<=n; ++i){
        for(int j=2; j<=n; ++j){
            x[i][j]+=x[i][j-1];
        }
    }
    rep(i,q)cin>>a[i]>>b[i];
    rep(i,q){
        int ans=0;
        for(int j=a[i]; j<=b[i]; ++j){
            ans+=x[j][b[i]];
        }
        cout<<ans<<endl;
    }
}