#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int x, y, z, k;

int main() {
    cin >> x >> y >> z >> k;
    vector<ll> A(x, 0);
    for(int i = 0; i < x; ++i) cin >> A.at(i);
    vector<ll> B(y, 0);
    for(int i = 0; i < y; ++i) cin >> B.at(i);
    vector<ll> C(z, 0);
    for(int i = 0; i < z; ++i) cin >> C.at(i);
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    vector<ll> ABC;
    for(int a = 0; a < x; ++a) {
        for(int b = 0; b < y; ++b) {
            if((a+1)*(b+1) > k) break;
            for(int c = 0; c < z; ++c) {
                if((a+1)*(b+1)*(c+1) > k) break;
                ABC.emplace_back(A.at(a)+B.at(b)+C.at(c));
            }
        }
    }
    sort(ABC.begin(), ABC.end(), greater<ll>());

    for(int i = 0; i < k; ++i) {
        cout << ABC.at(i) << endl;
    }
}