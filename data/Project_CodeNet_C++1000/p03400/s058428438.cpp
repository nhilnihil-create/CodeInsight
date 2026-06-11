#include<iostream>
using namespace std;

int main() {
    int N, D, X; cin >> N >> D >> X;
    int A[N];
    int sum = 0;
    for (int i = 0 ; i < N; i++) {
        cin >> A[i];
        sum += (D + A[i] - 1) / A[i];
    }
    cout << sum + X << endl;
}
