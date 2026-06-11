#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i];
    int l = 0, r = 0;
    sort(all(A));
    for(int i = 0; i < M; i++){
        if(A[i] < X) l++;
        else r++;
    }
    cout << min(l, r) << endl;
}
