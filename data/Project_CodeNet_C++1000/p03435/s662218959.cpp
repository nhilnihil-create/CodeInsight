#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a[3];
    int b[3];
    int c[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            if(c[0][i] - c[0][j] != c[1][i] - c[1][j] ||
                c[1][i] - c[1][j] != c[2][i] - c[2][j]){
                cout << "No\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            if(c[i][0] - c[j][0] != c[i][1] - c[j][1] ||
                c[i][1] - c[j][1] != c[i][2] - c[j][2]){
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}