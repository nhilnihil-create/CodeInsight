#include<bits/stdc++.h>
using namespace std;

int main() {
    int A, N, r;
    cin >> N;
    cin >> A;
    r = N % 500;
    if (r <= A) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}