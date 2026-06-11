#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    int cnt_R = 0;
    int cnt_B = 0;
    
    for (int i = 0; i < N; i++){
        if (S[i] == 'R'){
            cnt_R++;
        }
        else {
            cnt_B++;
        }
    }
    
    if (cnt_R > cnt_B){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl; 
    }
}