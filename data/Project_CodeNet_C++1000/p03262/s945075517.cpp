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

int main(){
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> x(N);
    for(int i = 0; i < N; i++) cin >> x[i];
    for(int i = 0; i < N; i++){
        x[i] = abs(X - x[i]);
    }
    ll min_n = x[0];
    for(int i = 1; i < N; i++) min_n = gcd(min_n, x[i]);
    cout << min_n << endl;

}