#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> data(3, vector<char> (3));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> data.at(i).at(j);
        }
    }

    string ans;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j) ans += data.at(i).at(j);
        }
    }

    cout << ans << endl;
}