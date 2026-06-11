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
template<typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

template<typename T>
T lcm(T a, T b){
  return a * b / gcd(a, b);
}
int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    ll ans = A[0];
    for(int i = 1; i < N; i++){
        ans = gcd(ans, A[i]);
    }
    cout << ans << endl;
}