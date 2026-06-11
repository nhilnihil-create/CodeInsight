#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<30;
const ll LINF = 1LL<<58;
const ll mod = 1000000007;

ll gcd(ll a, ll b) {
    return b != 0 ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(){
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = k+1; i < n+1; i++){
        ll l = (n-k)/i+1, m = i - k;
        ans += (l) * m;
        if(k==0) ans -= 1;
        //cout << ans << endl;
        ll a =  max(l * i - 1 - n, 0LL);
        ans -= a;
        //cout << "l: " << l << " m: " << m <<" minus: " << a << endl;
    }
    cout << ans << endl;
    return 0;
}