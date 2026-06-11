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
    int N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    sort(all(H));
    ll min_n = LL_INF;
    for(int i = 0; i < N - K + 1; i++){
        min_n = min(min_n, H[i + K - 1] - H[i]);
    }
    cout << min_n << endl;
}