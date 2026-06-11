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
    int n,m,X,Y;
    cin>>n>>m>>X>>Y;
    int x[n],y[m];
    int xmax=-200;
    int ymin=200;
    for(int i=0;i<n;i++){
        cin>>x[i];
        xmax=max(xmax,x[i]);
    }
    for(int i=0;i<m;i++){
        cin>>y[i];
        ymin=min(ymin,y[i]);
    }

    bool ans=false;

    for(int i=X+1;i<=Y;i++){
        if(xmax<i && ymin>=i){
            ans=true;
        }
    }

    if(ans) cout<<"No War"<<endl;
    else cout<<"War"<<endl;
}