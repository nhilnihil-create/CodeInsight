#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long A, B;
    cin >> A >> B;
    int K;
    cin >> K;


    for (int i = 0; i < K; i++){

        if (i % 2 == 0){
            if (A % 2 == 1){
                A = A - 1;
            }
            B = B + A / 2;
            A = A / 2;
        }
        
        if (i % 2 == 1){
            if (B % 2 == 1){
                B = B - 1;
            }
            A = A + B / 2;
            B = B / 2;
        }
    }

    cout << A << " " << B << endl;
}