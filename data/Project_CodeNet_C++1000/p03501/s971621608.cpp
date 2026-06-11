#include <bits/stdc++.h>
using namespace std;

int main() {
    int T,A,B;
    cin >> T >> A >> B;

    int C = T*A;
    
    if(C > B)
        cout << B << endl;
    else
        cout << C << endl;
}