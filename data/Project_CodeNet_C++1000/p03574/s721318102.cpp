#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int h,w;
vector<vector<char>> str(100,vector<char>(100));

void f(vector<vector<char> >& str,int a,int b){
    int cnt=0;
    if(str[a+1][b+1]=='#') cnt++;
    if(str[a][b+1]=='#') cnt++;
    if(str[a-1][b+1]=='#') cnt++;
    if(str[a+1][b]=='#') cnt++;
    if(str[a-1][b]=='#') cnt++;
    if(str[a][b-1]=='#') cnt++;
    if(str[a-1][b-1]=='#') cnt++;
    if(str[a+1][b-1]=='#') cnt++;
    str[a][b]='0'+cnt;
}

int main(){
    cin>>h>>w;
    rep(i,h) rep(j,w) cin>>str[i+1][j+1];

    rep(i,h){
        rep(j,w){
            if(str[i+1][j+1]=='.') f(str,i+1,j+1);
        }
    }

    rep(i,h){
        rep(j,w) cout<<str[i+1][j+1];
        cout<<"\n";
    }
    return 0;
}