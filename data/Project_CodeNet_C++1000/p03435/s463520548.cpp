#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<vector<int>> c(3, vector<int>(3));
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> c[i][j];
        }
    }
    int a;
    vector<int> b;
    for (int i=0; i<3; i++){
        a = min(c[i][0], min(c[i][1], c[i][2]));
        if (i == 0){
            for (int j=0; j<3; j++) b.emplace_back(c[i][j] - a);
        } else{
            for (int j=0; j<3; j++){
                if (a + b[j] != c[i][j]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}