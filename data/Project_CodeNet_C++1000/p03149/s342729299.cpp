#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int S[4];
    int count = 0;

    for (int i = 0; i < 4; i++){
        cin >> S[i];
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                for (int l = 0; l < 4; l++){
                    if (S[i] == 1 && S[j] == 9 && S[k] == 7 && S[l] == 4){
                        count++;
                    }
                }
            }
        }
    }
    
    if (count > 0){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}