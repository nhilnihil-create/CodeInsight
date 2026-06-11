#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,D,X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D; j += A[i]){
            X++;
        }
    }
    cout << X << endl;
}
