#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
typedef pair<int,int> P;
const int INF=1e9;
const int MOD= 1000000007;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h) rep(j,w) cin>>a[i][j];
    vector<vector<int>> dat(h,vector<int>(w));
    dat[0][0]++;
    rep(i,h) rep(j,w){
        if(i==0&&j==0) continue;
        if(0<=i-1&&a[i-1][j]=='.') dat[i][j]+=dat[i-1][j];
        if(0<=j-1&&a[i][j-1]=='.') dat[i][j]+=dat[i][j-1];
        dat[i][j]%=MOD;
    }
    cout<<dat[h-1][w-1];
}