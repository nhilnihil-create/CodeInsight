#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
int lcm(int a, int b) {return a * b / gcd(a, b);}   //最小公倍数

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = INF;
    for (long long i = 0; i <= 1000000;i++)
    {
        ans = min(ans,i * 2 * c + max(0LL, x - i) * a + max(0LL, y - i) * b);
    }
    cout << ans << endl;
}