#include <bits/stdc++.h>
using namespace std;

int main() {
    char A,B;
    cin >> A >> B;
    
    if(A == B){
        cout << "=";
    }else if(A < B){
        cout << "<";
    }else{
        cout << ">";
    }
    return 0;
}