#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<vector<int>> A(2, vector<int>(N));
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }
    
    int max = 0;
    for(int p = 0; p < N; p++){
        int ans = 0;
        for(int j = 0; j < N; j++){
            if(j < p){
                ans += A.at(0).at(j);
            }else if(j == p){
                ans += A.at(0).at(j) + A.at(1).at(j);
            }else{
                ans += A.at(1).at(j);
            }
        }
        if(ans > max){
            max = ans;
        }
    }

    cout << max << endl;
}