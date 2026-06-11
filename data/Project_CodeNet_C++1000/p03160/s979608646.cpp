#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n], B[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    B[0] = 0;    B[1] = abs(A[1] - A[0]);
    for(int i = 2; i < n; i++){
        int one = abs(A[i] - A[i-1]), two = abs(A[i] - A[i-2]);
        B[i] = min(B[i-1] + one, B[i-2] + two);
    }
    cout << B[n-1];
}

