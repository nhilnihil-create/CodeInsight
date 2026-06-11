#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    vv c(3, vi (3));
    rep(i,3)rep(j,3)cin>>c[i][j];
    
    rep(j,3)rep(i,2){
        c[i][j] -= c[i+1][j];
    }
    
    rep(i,2){
        if(c[i][0]!=c[i][1]){
            cout << "No" << endl;
            return 0;
        }
        if(c[i][2]!=c[i][1]){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}