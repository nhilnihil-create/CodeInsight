#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    int n, k; cin >> n >> k;
    vector<ll> V(n, 0);
    for(int i = 0; i < n; ++i) cin >> V.at(i);

    ll ans = 0;
    for(int left = 0; left <= min(n, k); ++left) {
        // cout << left << endl;
        // 左からleft個取得する
        priority_queue< ll, vector<ll>, greater<ll> > ansque;
        for(int i = 0; i < left; ++i) ansque.push(V.at(i));
        // cout << "ok" << endl;

        for(int right = 0; right+left <= min(n, k); ++right) {
            // cout << right << endl;
            priority_queue< ll, vector<ll>, greater<ll> > rightque;
            rightque = ansque;
            for(int j = 0; j < right; ++j) rightque.push(V.at(n-1-j));
            
            int gomi = k-(right+left);
            for(int j = 0; j < min(right+left, gomi); ++j) {
                ll now = rightque.top();
                if(now < 0) rightque.pop();
                else break;
            }

            ll sum = 0;
            while(!rightque.empty()) {
                sum += rightque.top();
                rightque.pop();
            }
            chmax(ans, sum);
        }
    }
    cout << ans << endl;
}