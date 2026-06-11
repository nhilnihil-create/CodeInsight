#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

const double pie = acos(-1.0);

// 最大公約数
ll gcd(ll a, ll b)
{
   if (a%b == 0) {
       return(b);
   } else {
       return(gcd(b, a%b));
   }
}

// 最小公倍数
ll lcm(ll a, ll b){
   return a * b / gcd(a, b);
}

//素数判定
bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(unsigned i = 5; i * i <= n; i += 6) {
        if(n % i     == 0) return false; // (6の倍数)-1
        if(n % (i+2) == 0) return false; // (6の倍数)+1
    }
    return true;
}

void solve() {
    ll n, m; cin >> n >> m;
    ll a = max(n, m), b = min(n, m);
    if(b == 1 && a == 1) cout << 1 << endl;// 1*1
    else if(b == 1 && a == 2) cout << 0 << endl; // 1*2
    else if(b == 1) cout << a-2 << endl; // 1*3~
    else if(b == 2) cout << 0 << endl; // 2*~
    else cout << (b-2)*(a-2) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
