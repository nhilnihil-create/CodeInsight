#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<vector<int>> c(3, vector<int>(3));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> c.at(i).at(j);
        }
    }

    string ans="Yes";
    if(c.at(1).at(0)-c.at(0).at(0)!=c.at(1).at(1)-c.at(0).at(1)||c.at(1).at(2)-c.at(0).at(2)!=c.at(1).at(1)-c.at(0).at(1)) ans="No";
    if(c.at(2).at(0)-c.at(1).at(0)!=c.at(2).at(1)-c.at(1).at(1)||c.at(2).at(2)-c.at(1).at(2)!=c.at(2).at(1)-c.at(1).at(1)) ans="No";
    if(c.at(0).at(1)-c.at(0).at(0)!=c.at(1).at(1)-c.at(1).at(0)||c.at(2).at(1)-c.at(2).at(0)!=c.at(1).at(1)-c.at(1).at(0)) ans="No";
    if(c.at(0).at(2)-c.at(0).at(1)!=c.at(1).at(2)-c.at(1).at(1)||c.at(2).at(2)-c.at(2).at(1)!=c.at(1).at(2)-c.at(1).at(1)) ans="No";

    cout << ans << endl;
}