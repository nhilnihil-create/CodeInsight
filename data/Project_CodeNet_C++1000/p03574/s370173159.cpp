#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
int main() {
    int h,w;
    string s[50];
    cin>>h>>w;
    rep(i,h) cin>>s[i];
    const int x[8]={-1,0,1,-1,1,-1,0,1};
    const int y[8]={-1,-1,-1,0,0,1,1,1};
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#') continue;
            int num=0;
            rep(k,8){
                if(i+y[k]<0||i+y[k]>=h) continue;
                if(j+x[k]<0||j+x[k]>=w) continue;
                if(s[i+y[k]][j+x[k]]=='#') num++;
            }
            s[i][j]=char(num+'0');
        }
    }
    rep(i,h) cout<<s[i]<<endl;
}