#include <bits/stdc++.h>
using namespace std;

int main() {
    int D,N;
    cin >> D >>N;
    if(D==0) {
        if (N == 100) {
            N = 101;
        }
        cout << N << endl;
    }else if(D==1) {
        if (N == 100) {
            N = 10100;
            cout << N << endl;
            exit(0);
        }
        cout << 100 * N << endl;
    }else if (D==2) {
        if (N == 100) {
            N = 1010000;
            cout << N << endl;
            exit(0);
        }
        cout << 10000 * N <<endl;
    }
}