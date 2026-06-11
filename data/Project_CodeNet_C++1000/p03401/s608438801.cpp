#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    ll sum = abs(A[0]) + abs(A.back());
    for(int i = 1; i < N; i++) sum += abs(A[i] - A[i - 1]);

    for(int i = 0; i < N; i++){
        ll min_n = sum;
        if(i == 0){
            min_n += -abs(A[i]) - abs(A[i + 1] - A[i]) + abs(A[i + 1]);
        }else if(i == N - 1){
            min_n += -abs(A[i]) - abs(A[i] - A[i - 1]) + abs(A[i - 1]);
        }else{
            min_n += -abs(A[i] - A[i - 1]) - abs(A[i] - A[i + 1]) + abs(A[i + 1] - A[i - 1]);
        }
        cout << min_n << endl;
    }
}