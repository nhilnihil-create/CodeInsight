#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    int n,m,c;
    cin>>n>>m>>c;
    int b[m];
    rep(i,m) cin>>b[i];
    int a[n][m];
    rep(i,n) rep(j,m) cin>>a[i][j];

    int count=0;

    rep(i,n){
        int Sum=0;
        rep(j,m){
            Sum+=b[j]*a[i][j];
        }
        if(Sum+c>0) count++;
    }

    cout<<count<<endl;
}