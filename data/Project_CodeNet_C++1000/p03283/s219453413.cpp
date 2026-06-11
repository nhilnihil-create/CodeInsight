#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int a[510][510];

int main(){
    int n,m,Q;
    cin>>n>>m>>Q;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,m){
        int l,r;
        cin>>l>>r;
        l--,r--;
        a[l][r]++;
    }

    vector<vector<int>> s(n+1,vector<int>(n+1,0));

    rep(i,n){
        rep(j,n){
            s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
        }
    }
    
    while(Q--){
        int p,q;
        cin>>p>>q;
        p--;
        cout<<s[q][q]-s[p][q]-s[q][p]+s[p][p]<<endl;
    }
}
