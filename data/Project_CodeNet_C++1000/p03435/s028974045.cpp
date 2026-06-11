#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> c(3,vector<int>(3));
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> c.at(i).at(j);
        }
    }

    vector<vector<int>> d(3,vector<int>(2));

    bool ans1=true;
    bool ans2=true;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3-1; j++){
            d[i][j]=c[i][j]-c[i][j+1];
        }
    }
    for (int j = 0; j < 3-1; j++){
        if(d[0][j]!=d[1][j] || d[1][j]!=d[2][j]){
            ans1=false;
        }
    }

    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3-1; i++){
            d[j][i]=c[i][j]-c[i+1][j];
        }
    }
    for (int j = 0; j < 3-1; j++){
        if(d[0][j]!=d[1][j] || d[1][j]!=d[2][j]){
            ans2=false;
        }
    }

    if(ans1&&ans2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    
}