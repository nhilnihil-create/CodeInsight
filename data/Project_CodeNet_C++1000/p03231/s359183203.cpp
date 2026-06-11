#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

ll GCD(ll a, ll b) {
    return (b > 0) ? GCD(b, a % b) : a;
}

ll LCM(ll a, ll b) {
    return a / GCD(a, b) * b;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if(n % m == 0){
        bool v = true;
        rep(i, m)if(s[i*(n/m)] != t[i])v = false;
        if(v)cout << n << endl;
        else cout << -1 << endl;
    }else if(m % n == 0){
        bool v = true;
        rep(i, n)if(s[i] != t[i*(m/n)])v = false;
        if(v)cout << m << endl;
        else cout << -1 << endl;
    }else{
        bool v = true;
        int g = GCD(n, m);
        rep(i, g)if(s[i*(n/g)] != t[i*(m/g)])v = false;
        if(v)cout << LCM(n, m) << endl;
        else cout << -1 << endl;
    }
    
}