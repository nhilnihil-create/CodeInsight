#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 
int main() {
    int c[3][3];
    int a[3] = {0}, b[3] = {0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++){
        b[i] = c[0][i] - a[0];
    }
    for(int i = 0; i < 3; i++){
        a[i] = c[i][0] - b[0];
    }

    bool yes = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a[i] + b[j] != c[i][j]){
                yes = false;
            }
        }
    }
    if(yes) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}