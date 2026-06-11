#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

ll gcd(ll a, ll b){
    ll num1, num2;
    num1 = max(a, b);
    num2 = min(a, b);
    if(num1 % num2 == 0){
        return num2;
    }
    return gcd(num1 % num2, num2);
}

int main() {
    ll N, M, n, m, d;
    ll ans;
    string S, T;
    cin >> N >> M >> S >> T;

    d = gcd(N, M);
    n = N / d;
    m = M / d;

    bool hasAns = true;
    rep(i, d){
        if(S[i * n] != T[i * m]){
            hasAns = false;
            break;
        }
    }
    if(hasAns){
        ans = N * M / d;
    } else {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}
