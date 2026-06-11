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
    char c[2][3];
    rep(i,0,1){
        rep(j,0,2){
            cin>>c[i][j];
        }
    }
    bool flag = true;
    rep(i,0,1){
        rep(j,0,2){
            if(c[i][j]!=c[1-i][2-j]){
                flag = false;
                break;
            }
        }
    }

    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}