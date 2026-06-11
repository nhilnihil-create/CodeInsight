#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);

int main() {
    int N; cin >> N;
    vecl A(N),B(N);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];
    ll total = 0;
    priority_queue<ll> differ;
    int ans = 0;
    REP(i,N) {
        if(A[i] < B[i]) {
            ans++;
            total += B[i]-A[i];
        } else if(A[i] > B[i]) differ.push(A[i]-B[i]);
    }
    if(total == 0) {
        cout << 0 << endl;
        return 0;
    }
    while(1) {
        if(differ.empty()) {
            cout << -1 << endl;
            return 0;
        }
        total -= differ.top();
        ans++;
        if(total <= 0) break;
        differ.pop();
    }
    cout << ans << endl;
}