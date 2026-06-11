#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

//aとbの最大公約数を返し、ax+by=gcd(a,b)を満たすようにx,yを変更する
ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b == 0) x = 1, y = 0;
    else{
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    }
    return d;
}

int main(){
    int T;
    cin >> T;
    rep(i, T){
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        if(A < B || B > D) {cout << "No" << endl; continue;}
        ll G = gcd(B, D);
        A %= B;
        if(A+((B-1-A)/G)*G > C) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}