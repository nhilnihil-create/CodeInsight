#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int x;

int main() {
    cin >> x;
    int ans = 1;
    for(int i = 2; i <= x; ++i) {
        int ch = i*i;
        while(ch <= x) {
            chmax(ans, ch);
            ch *= i;
        }
    }
    cout << ans << endl;
}