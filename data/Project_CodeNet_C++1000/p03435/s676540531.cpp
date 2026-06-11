#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<vector<int>> c(3, vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cin >> c[i][j];
    }

    vector<int> diff1(3, 0);
    for(int i = 1; i < 3; i++) diff1[i] = c[0][i] - c[0][0];

    string res = "Yes";
    for(int i = 1; i < 3; i++){
        for(int j = 1; j < 3; j++){
            if(c[i][j] - c[i][0] != diff1[j]) res = "No";
        }
    }

    cout << res << endl;
    return 0;
}