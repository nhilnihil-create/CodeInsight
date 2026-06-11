#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, q, l, r;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> a(n+1), b(n+1);
    for (ll i=1; i<n; i++){
        if (s[i-1] == 'A' && s[i] == 'C'){
            a[i] += a[i-1] + 1;
            b[i+1] += b[i] + 1;
        }
        else {
            a[i] = a[i-1];
            b[i+1] = b[i];
        }
    }
    rep1(i, q){
        cin >> l >> r;
        cout << b[r] - a[l-1] << endl;
    }
}