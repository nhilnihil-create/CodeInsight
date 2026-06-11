#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,t;
    cin >> n >> t;
    vector<vector<int>> ct(n,vector<int>(2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin >> ct.at(i).at(j);
      }
    }
    int ans = 10000;
    for(int i=0; i<n; i++){
        if(ct.at(i).at(1) > t){
            continue;
        }
        else{
            if(ans > ct.at(i).at(0)){
                ans = ct.at(i).at(0);
            }
        }
    }
    if(ans == 10000){
        cout << "TLE" << endl;
    }
    else{
        cout << ans << endl;
    }
}