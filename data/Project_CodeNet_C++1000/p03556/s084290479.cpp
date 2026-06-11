#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;

int main() {
    ll n; cin >> n;
    ll ans = 1;
    for (ll i = 1; i <= n; ++i) {
        if(n >= i * i)ans = i * i;
    }
    print(ans);
}