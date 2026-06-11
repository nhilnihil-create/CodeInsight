#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<char> C(6);

    for(int i = 0; i < 6; i++){
        cin >> C[i];
    }

    int ans = 0;

    if(C[0] == C[5]){
        ans++;
    }
    if(C[1] == C[4]){
        ans++;
    }
    if(C[2] == C[3]){
        ans++;
    }

    if(ans == 3){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
        

    

} 