#include <bits/stdc++.h>
using namespace std;

int main() {
    long long L[100];
    L[0] = 2;
    L[1] = 1;
    int N;
    cin >> N;

    for(int i = 2; i <= N; i++) {
        L[i] = L[i - 1] + L[i - 2];
    }

    if(N == 0) {
        cout << L[0] << endl;
    } else if(N == 1) {
        cout << L[1] << endl;
    } else {
        cout << L[N] << endl;
    }
    
    return 0;
}