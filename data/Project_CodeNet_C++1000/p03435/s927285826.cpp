#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int c[3][3];
    bool judge=true;
    rep(i,3){
        rep(j,3){
            cin>>c[i][j];
        }
    }
    int x,y,z;
    for(int i=0;i<2;i++){
        for(int j=i+1;j<3;j++){
            x=c[i][0]-c[j][0];
            y=c[i][1]-c[j][1];
            z=c[i][2]-c[j][2];
            if(!(x==y && y==z)){
                judge=false;
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=i+1;j<3;j++){
            x=c[0][i]-c[0][j];
            y=c[1][i]-c[1][j];
            z=c[2][i]-c[2][j];
            if(!(x==y && y==z)){
                judge=false;
            }
        }
    }
    if(judge){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}