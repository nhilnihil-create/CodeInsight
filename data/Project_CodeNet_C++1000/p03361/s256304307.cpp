#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 
int main(){
    int X,Y;
    cin>>X>>Y;
    string board[60];
    rep(i,X) cin>>board[i];
    int dx[4]={1,0,0,-1};
    int dy[4]={0,1,-1,0};
    bool judge=true;
    rep(i,X){
        rep(j,Y){
            int count=0;
            if(board[i][j]=='#'){
            rep(k,4){
                    int x,y;
                    x=i+dx[k];
                    y=j+dy[k];
                    if(x>=0&&x<X&&y>=0&&y<Y&&board[x][y]=='#') count++;
            }
            if(count==0) judge=false;

        }
    }
    }

    if(judge) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}