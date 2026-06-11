#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n, m;

int main() {
    cin >> n >> m;
    vector<ll> xvec(n, 0);
    vector<ll> yvec(n, 0);
    vector<ll> zvec(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> xvec.at(i) >> yvec.at(i) >> zvec.at(i);
    }

    ll ans = 0;
    for(int i = -1; i <= 1; i+=2) {
        for(int j = -1; j <= 1; j+=2) {
            for(int k = -1; k <= 1; k+=2) {
                ll sum = 0;
                vector<ll> ansvec;
                for(int l = 0; l < n; ++l) {
                    ansvec.emplace_back(xvec.at(l)*i + yvec.at(l)*j + zvec.at(l)*k);
                }
                sort(ansvec.begin(), ansvec.end(), greater<ll>());
                for(int l = 0; l < m; ++l) sum += ansvec.at(l);
                chmax(ans, sum);
            }
        }
    }
    
    cout << ans << endl;
}