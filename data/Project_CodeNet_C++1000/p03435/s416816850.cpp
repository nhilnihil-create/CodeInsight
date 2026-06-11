#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    vector<vector<int>>c(3,vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> c[i][j];
        }
    }
    bool judge=false;
    for(int i=-200;i<200;i++){
        for(int j=-200;j<=200;j++){
            for(int k=-200;k<=200;k++){
                int x=c[0][0]-i;
                int y=c[0][1]-i;
                int z=c[0][2]-i;
                if(x+j==c[1][0]&&x+k==c[2][0]&&y+j==c[1][1]&&y+k==c[2][1]&&z+j==c[1][2]&&z+k==c[2][2]){
                    judge=true;
                    break;
                }
            }
        }
    }
    if(judge) cout << "Yes" << endl;
    else cout << "No" << endl;
}