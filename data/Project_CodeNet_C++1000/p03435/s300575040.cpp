#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> A(3, vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> A.at(i).at(j);
        }
    }
    vector<int> a(3), b(3);
    a.at(0) = 0;
    b.at(0) = A.at(0).at(0);
    b.at(1) = A.at(0).at(1);
    b.at(2) = A.at(0).at(2);
    a.at(1) = A.at(1).at(0) - b.at(0);
    a.at(2) = A.at(2).at(0) - b.at(0);
    bool ans = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(A.at(i).at(j) != a.at(i) + b.at(j)){
                ans = false;
            }
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}