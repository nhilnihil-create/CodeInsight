#include <bits/stdc++.h>
using namespace std;
int main(){
    //write code  here
    int A,B,K;
    cin >> A >> B >> K;
    for (int i = 0; i < K/2; ++i) {
        if (A%2) A--;
        A /= 2;
        B += A;

        if (B%2) B--;
        B /= 2;
        A += B;
    }
    if (K%2 == 1){
        if (A%2) A--;
        A /= 2;
        B += A;
    }

    cout << A << " " << B << endl;
    return 0;
}