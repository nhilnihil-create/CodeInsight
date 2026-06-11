#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A,B;
    cin >> A >> B;
    if(A < B){
        int temp = A;
        A = B;
        B = temp;
    }
    if(2 <= A-B){
        cout << 2*A-1 << endl;
    }else{
        cout << A+B << endl;
    }
    return 0;
}