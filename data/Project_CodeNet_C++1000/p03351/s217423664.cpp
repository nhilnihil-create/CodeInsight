#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if(max(A,C) - min(A,C) <= D){
        cout << "Yes" << endl;
    }
    else if(max(A,B) - min(A,B) <= D && max(B,C) - min(B,C) <= D){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}