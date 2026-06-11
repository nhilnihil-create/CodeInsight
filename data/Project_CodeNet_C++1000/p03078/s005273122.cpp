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
    vector<ll> B(y, 0);
    vector<ll> C(z, 0);
    for(int i = 0; i < x; ++i) cin >> A.at(i);
    for(int i = 0; i < y; ++i) cin >> B.at(i);
    for(int i = 0; i < z; ++i) cin >> C.at(i);
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    vector<ll> AB;
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            ll sum = A.at(i)+B.at(j);
            AB.emplace_back(sum);
        }
    }

    sort(AB.begin(), AB.end(), greater<ll>());
    vector<ll> ABC;
    for(int i = 0; i < min(x*y, 3000); ++i) {
        for(int j = 0; j < z; ++j) {
            ll sum = AB.at(i) + C.at(j);
            ABC.emplace_back(sum);
        }
    }

    sort(ABC.begin(), ABC.end(), greater<ll>());
    for(int i = 0; i < k; ++i) {
        cout << ABC.at(i) << endl;
    }
}