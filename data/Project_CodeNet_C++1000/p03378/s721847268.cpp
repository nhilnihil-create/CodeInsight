#include <bits/stdc++.h>
using namespace std;

int main() {
    //N: マスの数0~Nまで, M: 料金所の数, X: 始めのマス
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M);
    for(int i=0; i<M; i++) cin >> A[i];

    int first_count=0;
    for(int i=X; i>=0; i--) {
        for(int j=0; j < M; j++) {
            if(i == A[j]) first_count++;
        }
    }

    int second_count=0;
    for(int i=X; i<N; i++) {
        for(int j=0; j < M; j++) {
            if(i == A[j]) second_count++;
        }
    }


    cout << min(first_count, second_count) << endl;


}
