#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    vector<vector<int>> p(3,vector<int>(3,0)), q;
    q=p;
    rep(i,3){
        rep(j,3){
            cin>>p[i][j];
        }
    }
    rep(i,3){
        rep(j,3){
            q[i][j]=p[j][i];
        }
    }
    bool ok=true;
    rep(i,2){
        if(!(p[i][0]-p[i+1][0]==p[i][1]-p[i+1][1] && p[i][1]-p[i+1][1]==p[i][2]-p[i+1][2])){
            ok=false;
        }
    }
    p=q;
    rep(i,2){
        if(!(p[i][0]-p[i+1][0]==p[i][1]-p[i+1][1] && p[i][1]-p[i+1][1]==p[i][2]-p[i+1][2])){
            ok=false;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}