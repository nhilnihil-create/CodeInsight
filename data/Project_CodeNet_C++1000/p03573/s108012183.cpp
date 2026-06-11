#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,B,C;
    cin >> A >> B >> C;

    if(A == B)
        cout << C << endl;
    else if(A == C)
        cout << B << endl;
    else 
        cout << A << endl;
}