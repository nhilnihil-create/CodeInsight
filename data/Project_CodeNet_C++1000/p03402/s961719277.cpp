#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int a,b;cin>>a>>b;
    char t[100][100];
    rep(i,100)rep(j,100){
        if(i<50)t[i][j]='#';
        else t[i][j]='.';
    }
    a--;b--;
    for(int i=0;i<50;i+=2){
        if(a==0)break;
        for(int j=0;j<100;j+=2){
            t[i][j]='.';a--;
            if(a==0)break;
        }
        if(a==0)break;
    }
    for(int i=51;i<100;i+=2){
        if(b==0)break;
        for(int j=0;j<100;j+=2){
            t[i][j]='#';b--;
            if(b==0)break;
        }
        if(b==0)break;
    }
    cout<<100<<" "<<100<<endl;
    rep(i,100){
        rep(j,100)cout<<t[i][j];
        cout<<endl;
    }
}