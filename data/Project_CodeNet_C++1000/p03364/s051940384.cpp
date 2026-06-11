#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n;cin>>n;
    char c[333][333];
    rep(i,0,n)rep(j,0,n)cin>>c[i][j];
    ll an=0,ok=1;
    rep(i,0,n){
        ok=1;
        rep(j,0,n){
            rep(k,0,n){
                if(j==k)continue;
                if(c[(j+i)%n][k]!=c[(i+k)%n][j])ok=0;
            }
        }
        if(ok)an+=n;
    }
    cout<<an<<endl;
}

    







