#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 1; i <= N; i++) {
        cin >> A[i - 1];
        A[i - 1] -= i;
    }
    sort(A.begin(), A.end());
    int b = A[N / 2];
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(A[i] - b);
    }
    cout << sum << endl;
}
