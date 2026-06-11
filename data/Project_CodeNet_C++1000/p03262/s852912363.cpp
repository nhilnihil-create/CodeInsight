#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i];
    b[0] = abs(x - a[n - 1]);
    _rep(i, 1, n) b[i] = abs(a[i] - a[i - 1]);
    ll GCD = b[0];
    rep(i, n){
        GCD = gcd(GCD, b[i]);
    }
    cout << GCD << endl;
}