#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int c[3][3];
    rep(i,3)rep(j,3) cin >> c[i][j];
    if(c[1][0]-c[0][0]==c[1][1]-c[0][1] && c[1][1]-c[0][1]==c[1][2]-c[0][2]){
        if(c[2][0]-c[0][0]==c[2][1]-c[0][1] && c[2][1]-c[0][1]==c[2][2]-c[0][2]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}