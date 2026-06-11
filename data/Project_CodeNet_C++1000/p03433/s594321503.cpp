#include<bits/stdc++.h>

using namespace std;

int main () {
    int A, N;
    cin >> N >> A;

    int b;
    b = (N % 500) - A;

    if (b <=0 ) {
        cout << "Yes" << endl;
    } else if (b > 0) {
        cout << "No" << endl;
    }
}