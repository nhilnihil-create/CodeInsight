#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    char c[3][3];
    rep(i,0,2){
        rep(j,0,2){
            cin>>c[i][j];
        }
    }
    cout<<c[0][0]<<c[1][1]<<c[2][2]<<endl;
    return 0;
}