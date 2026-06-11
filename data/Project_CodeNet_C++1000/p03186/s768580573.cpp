#include <bits/stdc++.h> // imports every library in c++
using namespace std; // ; is essential | says that you are USING the libraries

//  COMMAND TO USE WHEN RUNNING CODE: g++ day1.cpp -o day1 -std=c++11 -O2  | to run: ./(name of file)  //

int A, B, C;

int main() {
    cin >> A >> B >> C;
    if ( A + B >= C ) {
        cout << B + C << "\n";
    } else if ( A + B < C ) {
        int a;
        a = A + B + 1;
        cout << B + a << "\n";
    }
}