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
    int N, X;
    cin >> N >> X;
    vector<int> M(N);
    for(int i = 0; i < N; i++) cin >> M[i];
    sort(all(M));
    int sum = 0;
    for(int i = 0; i < N; i++) sum += M[i];
    int ans = N + (X - sum) / M[0];
    cout << ans << endl;
}
