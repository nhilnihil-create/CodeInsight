#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<ll> a(N),b(N);
    REP(i,N) cin >> a[i];
    REP(i,N) cin >> b[i];
    ll addition = 0;
    ll over = 0;
    REP(i,N) {
        if(b[i] > a[i]) {
            ll diff = b[i]-a[i];
            addition += (diff+1)/2;
            a[i] += 2*((diff+1)/2);
        }
        over += (a[i] - b[i]);
    }
    ll mi = addition - over;
    cout << ( mi >= 0 ? "Yes" : "No") << endl;
}

int main() {
    solve();
    return 0;
}