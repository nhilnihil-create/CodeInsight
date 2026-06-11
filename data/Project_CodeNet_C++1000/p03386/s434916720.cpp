#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,K;
    cin >> A >> B >> K;
    if(B-A+1 <= K*2) {
        for(int i = A; i <= B; i++) {
            cout << i << endl;
        }
        return 0;
    }
    for(int i = A; i < A+K; i++) {
        cout << i << endl;
    }
    for(int j = B-K+1; j <= B; j++) {
        cout << j << endl;
    }
}