#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    bool iftrue = false;
    vector<vector<ll>> c(3, vector<ll>(3));
    rep(i, 3){
        rep(j, 3){
            cin>>c[i][j];
        }
    }
    if(c[1][0] - c[0][0] == c[1][1] - c[0][1] && c[1][1] - c[0][1] == c[1][2] - c[0][2]){
        if(c[2][0] - c[1][0] == c[2][1] - c[1][1] && c[2][1] - c[1][1] == c[2][2] - c[1][2]){
            iftrue = true;
        }
    }
    if(iftrue) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}