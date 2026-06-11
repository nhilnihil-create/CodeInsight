#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;


int main() {
    ll N;
    cin >> N;
    vector<ll> X;
    for (ll i= 0;i<N;i++) {
        ll a;
        cin >> a;
        X.push_back(a);
    }
    vector<ll> A;
    A = X;
    sort(X.begin(),X.end());
    ll left = X.at((N-1)/2);
    ll right = X.at((N+1)/2);
    for (ll i = 0;i<N;i++) {
        if (A.at(i)<right) cout << right << endl;
        else cout << left << endl;
    }

}