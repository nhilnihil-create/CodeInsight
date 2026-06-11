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
    int a,b; cin>>a>>b;
    vector<vector<char>> ans(100,vector<char>(100,'#'));
    rep(i,50){
        rep(j,100){
            ans[i+50][j]='.';
        }
    }
    rep(i,a-1){
        int x=i%50; x*=2;
        int y=i/50; y*=2;
        ans[y][x]='.';
    }
    rep(i,b-1){
        int x=i%50; x*=2;
        int y=i/50; y*=2; y+=51;
        ans[y][x]='#';
    }
    cout<<"100 100"<<endl;
    rep(i,100){
        rep(j,100){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}