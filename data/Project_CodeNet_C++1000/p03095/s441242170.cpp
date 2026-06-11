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
    string S;
    cin >> S;
    map<char,ll> mp;
    for (ll i = 0;i<N;i++) {
        mp[S.at(i)]++;
    }
    ll cnt = 1;
    for (pair<char,ll> p : mp) {
        ll pattern = 1 + p.second;
        pattern %= MOD;
        cnt *= pattern;
        cnt %= MOD;
    }
    cout << cnt - 1 << endl;
    
}