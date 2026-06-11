#include <iostream>
#include <algorithm>

using namespace std;

void copy(int *to, int *from, int N){
    for(int i = 0; i < N; i++){
        to[i] = from[i];
    }
}

int main(){
    int N, K, Q;
    int A[2000];
    int B[2000];
    int C[2000];
    int D[2000];
    int ans;
    cin >> N >> K >> Q;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B, B+N);
    ans = B[Q-1] - B[0];
    int prev = 0;
    for(int i = 0; i < N; i++){
        if(prev != B[i]){
            int cnt = 0;
            int left = 0, right = -1;
            for(int j = 0; j < N; j++){
                if(A[j] >= B[i]) right++;
                if(A[j] < B[i] || j == N-1){
                //if(A[j] < B[i]){
                    if(right-left+1 >= K){
                        copy(C, A+left, right-left+1);
                        sort(C, C+right-left+1);
                        copy(D+cnt, C, right-left-K+2);
                        cnt += right-left-K+2;
                    }
                    left = j+1;
                    right = j;
                }
            }
            if(cnt < Q)break;
            else {
                sort(D, D+cnt);
                ans = min(ans, D[Q-1]-D[0]);
            }
        }
        prev = B[i];
    }
    cout << ans << endl;
}