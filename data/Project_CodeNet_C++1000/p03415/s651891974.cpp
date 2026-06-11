#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector <char>> c(3,vector<char>(3));
    
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++){
            cin >> c.at(i).at(j);
        }

    cout << c.at(0).at(0) << c.at(1).at(1) << c.at(2).at(2) << endl;
}