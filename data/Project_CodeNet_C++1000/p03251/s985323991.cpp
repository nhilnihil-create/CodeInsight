#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m,x,y;cin>>n>>m>>x>>y;
    int maxi=x+1,mini=y;
    rep(i,n){
        int X;cin>>X;
        chmax(maxi,X);
    }
    rep(i,n){
        int Y;cin>>Y;
        chmin(mini,Y);
    }
    //cout<<maxi<<" "<<mini<<endl;
    if(maxi>=mini)cout<<"War"<<endl;
    else cout<<"No War"<<endl;
}