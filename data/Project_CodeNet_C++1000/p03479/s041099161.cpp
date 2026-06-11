#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    ll X,Y;
    cin >> X >> Y;
    int ret = 0;
    while(X <= Y) {
        ret++;
        X *= 2;
    }
    cout << ret << endl;
}