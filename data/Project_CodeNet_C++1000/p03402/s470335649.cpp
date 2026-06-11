#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

int a,b;
char c[100][100];

int main(){
    cin>>b>>a;
    rep(i,100)rep(j,100){
        c[i][j]=(i<50?'#':'.');
    }
    a--;
    for(int i=51;a;i+=2)for(int j=0;j<100&&a;j+=2){
        c[i][j]='#';
        a--;
    }
    b--;
    for(int i=0;b;i+=2)for(int j=0;j<100&&b;j+=2){
        c[i][j]='.';
        b--;
    }
    cout<<"100 100\n";
    rep(i,100){
        rep(j,100)cout<<c[i][j];
        cout<<endl;
    }
}