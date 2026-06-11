#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;
const long long MOD = (long long)1e9 + 7;

int main(){
    vector<vector<int>> c(3, vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i <= 100; i++){
        if(i > c[0][0] || i > c[0][1] || i > c[0][2]) break;
        for(int j = 0; j <= 100; j++){
            if(j > c[1][0] || j > c[1][1] || j > c[1][2]) break;
            for(int k = 0; k <= 100; k++){
                if(k > c[2][0] || k > c[2][1] || k > c[2][2]) break;
                if(c[0][0] - i == c[1][0] - j && c[0][0] - i == c[2][0] - k){
                    if(c[0][1] - i == c[1][1] - j && c[0][1] - i == c[2][1] - k){
                        if(c[0][2] - i == c[1][2] - j && c[0][2] - i == c[2][2] - k){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}
