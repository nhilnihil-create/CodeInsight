#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> a(3);
    vector<int> b(3);
    vector<vector<int>> c(3,vector<int>(3));
    bool check = true;
    
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin >> c[i][j];
        }
    }

    
    vector<int> diffh(2);
    vector<int> diffw(2);
    int diff ;
    for(int j=1;j<3;j++) {
        diffw[j-1] = c[0][j] - c[0][j-1];
    }
    for(int i=1;i<3;i++) {
        for(int j=1;j<3;j++) {
            diff = c[i][j] - c[i][j-1];
            if(diff != diffw[j-1]) {
                check = false;
                break;
            }
        }
    }
    for(int i=1;i<3;i++) {
        diffh[i-1] = c[i][0] - c[i-1][0];
    }
    for(int j=1;j<3;j++) {
        for(int i=1;i<3;i++) {
            diff = c[i][j] - c[i-1][j];
            if(diff != diffh[i-1]) {
                check = false;
                break;
            }
        }
    }
    
    if(check) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
