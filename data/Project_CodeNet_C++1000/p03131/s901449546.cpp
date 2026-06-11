#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    ll K,A,B;
    cin >> K >> A >> B;
    if(B - A >= 2) {
        ll ret = 0;
        ret += A;
        K -= (A - 1);
        ret += (K / 2) * (B - A);
        ret += K % 2;
        cout << ret << endl;
    }
    else {
        cout << K + 1 << endl;
    }
}