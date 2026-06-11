#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int A, N, a;
    cin >> N;
    cin >> A;
    a = N%500;
    if (a <= A) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}