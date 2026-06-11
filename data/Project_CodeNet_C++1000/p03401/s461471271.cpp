#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<int> S(N+1);
    S[0] = A[0];
    S[N] = -A[N-1];
    for(int i = 1; i < N; i++){
        S[i] = (A[i] - A[i-1]);
    }
    int Kane = 0;
    for(int i = 0; i < N+1; i++){
        Kane += abs(S[i]);
    }
    for(int i = 1; i < N+1; i++){
        cout << Kane  - abs(S[i]) - abs(S[i-1]) +abs(S[i] + S[i-1]) << endl;
    }
}
