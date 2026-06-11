#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int h,w,ans=0;
    cin >> h >> w;
    int a[h][w],b[h][w];
    rep(i,h)rep(j,w){
        cin >> a[i][j];
        b[i][j] = 0;
    } 
    int flag = 0;
    rep(i,h){
        if(i%2==0){
            rep(j,w){
                if(a[i][j]%2) flag++;
                b[i][j] = flag;
            }
        }
        else{
            for(int j=w-1;0<=j;j--){
                if(a[i][j]%2) flag++;
                b[i][j] = flag;
            }
        }
    }
     rep(i,h){
        if(i%2==0){
            rep(j,w-1){
                if(b[i][j]%2) ans++;
            } 
            if(i+1<h&&b[i][w-1]%2) ans++;
        }
        else{
            for(int j=w-1;0<j;j--){
                if(b[i][j]%2) ans++;
            } 
            if(i+1<h&&b[i][0]%2) ans++;
        }
    }
    cout << ans << endl;
    rep(i,h){
        if(i%2==0){
            rep(j,w-1){
                if(b[i][j]%2) cout << i+1 <<' ' << j+1 << ' ' << i+1 <<' '<< j+2 << endl;
            } 
            if(i+1<h&&b[i][w-1]%2) cout << i+1 << ' ' <<w << ' ' << i+2 <<' '<< w << endl;
        }
        else{
            for(int j=w-1;0<j;j--){
                if(b[i][j]%2) cout << i+1 <<' '<< j+1 << ' ' << i+1 <<' '<< j << endl;
            } 
            if(i+1<h&&b[i][0]%2) cout << i+1 <<' '<< 1 << ' ' << i+2 <<' '<< 1 << endl;
        }
    }
}