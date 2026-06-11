#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 最大公約数(ユークリッドの互除法)
// O(log max(a, b))
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int n, ans = 0;
    cin >> n;
    n = 100000;
    vector<int> a(n);
    vector<int> front_gcd(n), back_gcd(n);
    rep(i, n) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    front_gcd[0] = a[0];
    rep2(i, 1, n) {
        front_gcd[i] = gcd(a[i], front_gcd[i-1]);
    }
    back_gcd[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        back_gcd[i] = gcd(a[i], back_gcd[i+1]);
    }
    ans = front_gcd[n-1];
    rep(i, n) {
        int res;
        if(i == 0) {
            res = back_gcd[1];
        }
        else if(i == n-1) {
            res = front_gcd[max(n-2, 0)];
        }
        else if(i+1 <= n-1 && i-1 >= 0){
            res = gcd(back_gcd[i+1], front_gcd[i-1]);
        }
        chmax(ans, res);
    }
    cout << ans << endl;
}