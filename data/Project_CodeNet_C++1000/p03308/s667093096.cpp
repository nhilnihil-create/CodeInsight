#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int A[110];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A+N);
    cout << A[N-1] - A[0] << endl;
}
