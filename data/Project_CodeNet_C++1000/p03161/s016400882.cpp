#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int A[n], B[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    if(k >= n) {
        cout << abs(A[0] - A[n-1]);
        return 0;
    }

    B[0] = 0;
    for(int i = 1; i < k; i++){
        B[i] = abs(A[i] - A[0]);
    }

    for(int i = k; i < n; i++){
        int temp = INT_MAX;
        for(int j = i-k; j < i; j++){
            temp = min(B[j] + abs(A[i]-A[j]), temp);
        }
        B[i] = temp;
    }
    cout << B[n-1];
}


