#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    cout<<100<<" "<<100<<endl;
    int a,b; cin>>a>>b; a--,b--;
    char board[100][100];
    rep(i,50)rep(j,100) board[i][j]='.';
    rep(i,50)rep(j,100) board[50+i][j]='#';
    int y=0,x=0;
    while(b--){
        board[y][x]='#';
        x+=2;
        if(x>99) x=0,y+=2;
    }
    y=99,x=0;
    while(a--){
        board[y][x]='.';
        x+=2;
        if(x>99) x=0,y-=2;
    }
    rep(i,100){
        rep(j,100){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    return 0;
}
