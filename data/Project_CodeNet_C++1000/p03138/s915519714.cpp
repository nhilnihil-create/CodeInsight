#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n, k;

int main() {
    cin >> n >> k;
    vector<ll> A(n, 0);
    for(int i = 0; i < n; ++i) cin >> A.at(i);

    vector<ll> vec1(45, 0);
    for(int i = 0; i < n; ++i) {
        int j = 0;
        while((1LL<<j) <= A.at(i)) {
            if(A.at(i)&(1LL<<j)) {
                vec1.at(j)++;
            }
            j++;
        }
    }
    vector<ll> vec0(45, 0);
    for(int i = 0; i < 45; ++i) vec0.at(i) = n-vec1.at(i);

    int limit = 0;
    vector<int> bitk(45, 0);
    while((1LL<<limit) <= k) {
        if(k&(1LL<<limit)) {
            bitk.at(limit)++;
        }
        limit++;
    }

    ll ans = 0;
    for(int i = 0; i <= limit; ++i) {
        ll sum = 0;
        ll now = 1;
        vector<int> bitck = bitk;
        if(bitk.at(i) == 1) {
            // i-1まで好きに選べる
            // ここでbitk.at(i)を0にするから実現できる
            bitck.at(i) = 0;
            for(int j = 0; j < 45; ++j) {
                if(j < i) {
                    if(vec0.at(j) >= vec1.at(j)) sum += vec0.at(j)*now;
                    else sum += vec1.at(j)*now;
                }else {
                    if(bitck.at(j) == 1) sum += vec0.at(j)*now;
                    else sum += vec1.at(j)*now;
                }
                now *= 2;
            }
        }else {
            for(int j = 0; j < 45; ++j) {
                if(bitck.at(j) == 1) sum += vec0.at(j)*now;
                else sum += vec1.at(j)*now;
                now *= 2;
            }
        }
        chmax(ans, sum);
    }
    cout << ans << endl;
}