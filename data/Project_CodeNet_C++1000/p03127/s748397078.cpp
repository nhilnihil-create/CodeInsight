#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    int n; cin >> n;
    vector<int> A(n, 0);
    for(int i = 0; i < n; ++i) cin >> A.at(i);

    ll ggg = A.at(0);
    for(int i = 1; i < n; ++i) ggg = GCD(ggg, A.at(i));

    cout << ggg << endl;
}