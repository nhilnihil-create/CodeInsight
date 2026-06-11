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
    char c[2][3];
    rep(i,2) rep(j,3) cin>>c[i][j];

    bool ans=true;

    if(c[0][0]!=c[1][2]||c[0][1]!=c[1][1]||c[0][2]!=c[1][0]){
        ans=false;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}