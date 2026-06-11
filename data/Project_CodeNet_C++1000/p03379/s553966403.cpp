#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    vector<ll> x(n, 0), y(n, 0);
    rep1(i, n){
        cin >> x[i];
        y[i] = x[i];
    }
    sort(y.begin(), y.end());
    ll ans = 0; 
    rep1(i, n){
        if (n%2 == 0){
            if (x[i] <= y[n/2-1]){
                cout << y[n/2] << endl;
            }
            else{
                cout << y[n/2-1] << endl;
            }
        }
    }
}