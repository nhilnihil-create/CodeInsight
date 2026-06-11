#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int A, B, C, X;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
    
    int max_A = X / 500;
    int count = 0;
    
    for(int i=min({max_A, A}); i>=0; i--){
        int tmp_X = X - i*500;

        int max_B = tmp_X / 100;
        for(int j=min({max_B, B}); j>=0; j--){
            int tmp_X_2 = tmp_X - 100*j;

            int require_C = tmp_X_2 / 50;
            if(require_C <= C){
                count += 1;
            }
        
        }
    }

    cout << count << endl;
    return 0;
}