#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    int sum = 0,j = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(abs(A[i]) > sum) {
            j = i;
            sum = abs(A[i]);
        }
    }
    cout << 2*N << endl;
    if(A[j] < 0) {
        cout << j+1 << " " << N << endl;
        cout << j+1 << " " << N << endl;
        for(int i = N; i >= 2; i--) {
            cout << i << " " << i-1 << endl;
            cout << i << " " << i-1 << endl;
        }
    }
    else {
        cout << j+1 << " " << 1 << endl;
        cout << j+1 << " " << 1 << endl;
        for(int i = 1; i <= N-1; i++) {
            cout << i << " " << i+1 << endl;
            cout << i << " " << i+1 << endl;
        }
    }
}