#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll h,w;
vector<vector<char>> s(100,vector<char>(100));

int main(){
    cin>>h>>w;
    rep(i,1,h+1) rep(j,1,w+1) cin>>s[i][j];
    bool flag=true;
    int cnt=0;
    rep(i,1,h+1){
        rep(j,1,w+1){
            if(s[i][j]=='#'){
                cnt++;
                if(s[i-1][j]!='#' && s[i+1][j]!='#' && s[i][j-1]!='#' && s[i][j+1]!='#') flag=false;
            }
        }
    }
    if(cnt!=0){
        if(flag) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
    else cout<<"Yes"<<"\n";
    return 0;
}