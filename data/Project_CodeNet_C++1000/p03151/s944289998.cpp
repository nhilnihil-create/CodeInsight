#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];
    vector<int> yoyu(N);
    REP(i,N) yoyu[i] = A[i] - B[i];

    sort(ALL(yoyu));
    reverse(ALL(yoyu));

    vector<int> yoyup;
    ll ans = 0;
    ll minus_sum = 0;
    REP(i,N) {
        if (yoyu[i] > 0) yoyup.push_back(yoyu[i]);
        else if (yoyu[i] < 0) {
            ans++;
            minus_sum += abs(yoyu[i]);
        }
    }

    while(!yoyup.empty()) {
        if (minus_sum <= 0) {
            cout << ans << endl;
            exit(0);
        }
        minus_sum -= yoyup.front(); yoyup.erase(yoyup.begin());
        ans++;
    }

    if (minus_sum >= 0) cout << -1 << endl;
    else cout << ans << endl;



}

int main() {
    solve();
    return 0;
}
