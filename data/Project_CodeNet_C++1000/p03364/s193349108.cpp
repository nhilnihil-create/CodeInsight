#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> S(n + 1, vector<char>(n + 1)), T(n + 1, vector<char>(n + 1));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> S[i][j];
        }
    }
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n;k++){
                T[j][k] = S[(i + j) % n][k];
            }
        }
        bool flag = false;
        for(int j = 0; j < n;j++){
            for(int k = j+1; k < n;k++){
                if(T[j][k] != T[k][j]) flag = true;
            }
        }
        if(!flag){
            ret += n;
        }
    }
    cout << ret << endl;
    return 0;
}