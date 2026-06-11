#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    ll N,K;
    cin >> N >> K;
    if(K % 2 == 0) {
        ll cnt = max(0ll,(N + K / 2) / K);
        cout << (N / K) * (N / K) * (N / K) + cnt * cnt * cnt << endl;
    }
    else {
        cout << (N / K) * (N / K) * (N / K) << endl;
    }
}