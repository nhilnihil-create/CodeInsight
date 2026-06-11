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
    int N, M;
    cin >> N >> M;
    vector<int> Good(M, 0);
    for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        vector<int> A(K);
        for(int j = 0; j < K; j++) cin >> A[j];
        for(int j = 0; j < K; j++) Good[A[j] - 1]++;
    }
    int count = 0;
//    for(int x : Good) cout << x << endl;
    for(int x : Good) if(x == N) count++;
    cout << count << endl;
}
