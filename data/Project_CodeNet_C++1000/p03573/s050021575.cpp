#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    if(A==B && B!=C)
        cout << C;
    else if(B==C && C!=A)
        cout << A;
    else
        cout << B;
    cout << endl;
}