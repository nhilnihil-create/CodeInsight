#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int p[509][509];
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        p[l][r]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            p[i][j]+=p[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            p[i][j]+=p[i-1][j];
        }
    }

    rep(i,q){
        int l,r;
        cin>>l>>r;
        cout<<p[r][r]+p[l-1][l-1]-p[l-1][r]-p[r][l-1]<<endl;
    }
}

