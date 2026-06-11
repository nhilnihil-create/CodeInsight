#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    bool jdg = true;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i < A[i]) {
            jdg = false;
        }
    }
    
    for (int i = 1; i < N; i++) {
        if (A[i - 1] + 1 < A[i]) {
            jdg = false;
        }
    }
  
    long long cnt = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] == A[i - 1] + 1) {
            cnt++;
        } else {
            cnt += A[i];
        }
    }
    
    cout << ((jdg) ? cnt : -1) << endl;
    return 0;
}