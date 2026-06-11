#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

vector<vector<int>> c(3,vector<int>(3));

int main(){
    rep(i,0,3) rep(j,0,3) cin>>c[i][j];
    bool flag=true;

    rep(i,1,3){
        if(c[0][i]-c[0][i-1]!=c[1][i]-c[1][i-1] || c[2][i]-c[2][i-1]!=c[1][i]-c[1][i-1]){
            flag=false;
            break;
        }
        if(c[i][0]-c[i-1][0]!=c[i][1]-c[i-1][1] || c[i][2]-c[i-1][2]!=c[i][1]-c[i-1][1]){
            flag=false;
            break;
        }
    }
    if(flag) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}
