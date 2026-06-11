//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m,q; cin>>n>>m>>q;
    vector<vector<int>> t(n,vector<int>(n,0)),s(n,vector<int>(n,0));
    rep(i,m){
        int l,r; cin>>l>>r;
        l--; r--; t[l][r]++;
    }
    rep(i,n) s[i][i]=t[i][i];
    rep(i,n-1) s[i][i+1]=t[i][i]+t[i][i+1]+t[i+1][i+1];
    rep(i,n-2){
        rep(j,n-i-2){
            s[j][j+i+2]=t[j][j+i+2]+s[j][j+i+1]+s[j+1][j+i+2]-s[j+1][j+i+1];
        }
    }
    rep(i,q){
        int a,b; cin>>a>>b;
        a--; b--;
        printf("%d\n",s[a][b]);
    }
}