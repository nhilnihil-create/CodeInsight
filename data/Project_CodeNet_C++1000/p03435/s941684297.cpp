#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int arr[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    
    int diff[3][3];
    
    for(int i = 0; i < 3; i++){
        diff[i][0] = arr[i][0] - arr[i][2];
        diff[i][1] = arr[i][0] - arr[i][1];
        diff[i][2] = arr[i][1] - arr[i][2];
    }
    
    
    bool check = true;
    for(int i = 0; i < 3; i++){
        if(diff[0][i] != diff[1][i] || diff[1][i] != diff[2][i] || diff[2][i] != diff[0][i]){
            check = false;
            break;
        }
    }
    
    if(check){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
}
