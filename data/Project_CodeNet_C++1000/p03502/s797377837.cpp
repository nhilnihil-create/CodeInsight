#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, s=0, x;
    cin >> N;
    x = N;
    while(1) {
        s += N%10;
        N /= 10;
        if (N==0) break;
    }
    if ( x%s ) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

}