#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D;
    cin >> A>>B>>C>>D;
    int de,ba;
    if(A<=B){
        de=A;
    }
    else{
        de=B;
    }
    if(C<=D){
        ba = C;
    }
    else{
        ba = D;
    }

    cout << de+ba << endl;

    return 0;
}