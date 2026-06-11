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

ll disit_sum(ll N) {
    ll ans = 0;
    while(N > 0) {
        ans += N%10;
        N /= 10;
    }
    return ans;
}

int main() {
    ll N; cin >> N;
    ll ans = disit_sum(N);

    ll deg;
    ll ex = 1;
    ll now = N;
    while(1) {
        deg = (now/ex)%10;
        now = now - (deg+1)*ex;
        //cout << now << endl;
        if(now <= 0) break;
        chmax(ans,disit_sum(now));

        ex *= 10;
    }
    cout << ans << endl;
}