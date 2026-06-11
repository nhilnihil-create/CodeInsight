#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    int r = x%y;
    if (r == 0) {
        return y;
    }
    return gcd(y, r);
}

ll mypow(ll x, ll n) {
    if (n == 0) return 1;
    if (n%2 == 0) return mypow(((x%mod)*(x%mod))%mod, n/2);
    else return ((x%mod) * mypow(((x%mod)*(x%mod))%mod, (n-1)/2))%mod;
}

int main(){
    int N;
    cin >> N;
    cout << N/3 << endl;
}