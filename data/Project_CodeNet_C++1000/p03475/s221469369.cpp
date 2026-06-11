#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n;

int main() {
    cin >> n;
    vector<ll> C(n-1, 0);
    vector<ll> S(n-1, 0);
    vector<ll> F(n-1, 0);
    for(int i = 0; i < n-1; ++i) {
        cin >> C.at(i) >> S.at(i) >> F.at(i);
    }

    for(int i = 0; i < n; ++i) {
        int start = i;
        vector<ll> cans(n, 0);
        for(int j = start; j < n-1; ++j) {
            if(j == start) {
                // startは始発電車
                cans.at(j+1) = S.at(j) + C.at(j);
            }else {
                ll next = cans.at(j);
                if(cans.at(j) % F.at(j) != 0) {
                    next += F.at(j) - (cans.at(j)%F.at(j));
                }
                cans.at(j+1) = C.at(j) + max(next, S.at(j));
            }
        }
        cout << cans.at(n-1) << endl;
    }
}