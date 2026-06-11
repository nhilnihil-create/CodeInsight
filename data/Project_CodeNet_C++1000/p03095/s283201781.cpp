#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;

int main() {
    ll n; cin >> n;
    string s; cin >> s;
    n = s.size();
    map<char,int> a;
    for (int i = 0; i < n; ++i) {
        a[s[i]]++;
    }
    int m = a.size();
    vector<int> b(m);
    int i = 0;
    for(auto it : a){
        b[i] = it.second;
        i++;
    }
    ll ans = 1;
    rep(i,m) {
        ans *= b[i] + 1;
        ans %= mod;
    }
    print(ans % mod - 1);
}
