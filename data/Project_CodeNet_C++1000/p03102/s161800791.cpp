#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for(int i = 0; i < M; i++) cin >> B[i];
    vector<vector<int>> A(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> A[i][j];
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        int sum = C;
        for(int j = 0; j < M; j++){
            sum += A[i][j] * B[j];
        }
        if(sum > 0) count++;
    }
    cout << count << endl;
}
