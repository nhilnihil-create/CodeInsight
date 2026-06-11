#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const ll mod = 1000000007;
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & 1) ret = ret * a % mod;
    return ret;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
string S;
ll A[105000], AB[105000], ABC[105000];
ll question;

int main() {
    cin >> S;
    S = "#" + S;
    for(int i = 1; i < S.size(); i++) {
        if(S[i] == 'C') {
            ABC[i] = (ABC[i-1] + AB[i-1]) % mod;
            AB[i] = AB[i-1];
            A[i] = A[i-1];
            continue;
        }
        if(S[i] == 'B') {
            ABC[i] = (ABC[i-1]) % mod;
            AB[i] = (AB[i-1] + A[i-1]) % mod;
            A[i] = A[i-1];
            continue;
        }
        if(S[i] == 'A') {
            ABC[i] = (ABC[i-1]) % mod;
            AB[i] = AB[i-1];
            A[i] = (A[i-1] + 1) % mod;
            continue;
        }
        if(S[i] == '?') {
            ABC[i] = (ABC[i-1] + AB[i-1] * beki(3, mod - 2)) % mod;
            AB[i] = (AB[i-1] + A[i-1] * beki(3, mod - 2)) % mod;
            A[i] = (A[i-1] + beki(3, mod - 2)) % mod;
            question++;
        }
    }
    cout << ABC[S.size() - 1] * beki(3, question) % mod << endl;
    return 0;
}
