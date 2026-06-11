#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
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
    const auto MAX = 1e5+1;
    // setup
    vector<int> cnt(MAX,0);
    vector<bool> is_prime(MAX,true);
    is_prime[0] = false;
    is_prime[1] = false;
    FOR(i,2,MAX) {
        if(!is_prime[i]) continue;
        int k = i + i;
        while(k < MAX) {
            is_prime[k] = false;
            k += i;
        }
    }

    FOR(i,1,MAX) {
        if(i%2) {
            if(is_prime[i] && is_prime[(i+1)/2]) cnt[i] = cnt[i-1]+1;
            else cnt[i] = cnt[i-1];
        }
        else cnt[i] = cnt[i-1];
    }
    int Q;
    cin >> Q;
    REP(_,Q) {
        int l,r;
        cin >> l >> r;
        if(l!=1) l -=2;
        cout << cnt[r] - cnt[l] << endl;
    }

}

int main() {
    solve();
    return 0;
}