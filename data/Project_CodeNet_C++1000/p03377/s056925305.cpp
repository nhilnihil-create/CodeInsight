#include <iostream>

using namespace std;

int main(){

    int A, B, X;

    cin >> A >> B >> X;

    if(A + B < X){
        cout << "NO" << endl;
    }else if(X < A){
        cout << "NO" << endl;
    }else if(X <= A + B){
        cout << "YES" << endl;
    }

    return 0;
}