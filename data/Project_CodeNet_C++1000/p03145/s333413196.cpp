#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(A > B && A > C) {
        cout << B*C/2 << endl;
    }
    else if(B > A && B > C) {
        cout << A*C/2 << endl;
    }
    else {
        cout << A*B/2 << endl;
    }
}

