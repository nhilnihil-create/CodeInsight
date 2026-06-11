#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using P = pair<i64, i64>;

#define overload3(_1, _2, _3, name, ...) name
#define rep1(i, n) for(i64 i = 0LL; i < (n); ++i)
#define rep2(i, a, b) for(i64 i = (a); i < (b); ++i)
#define rep(...) overload3(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()


void solve(long long N, long long K, std::vector<long long> a){
    vector<i64> b;
    rep(i, N){
        i64 sum = 0;
        rep(j, i, N){
            sum += a[j];
            b.emplace_back(sum);
        }
    }
    vector<bool> f(b.size(), true);
    i64 ans = 0;
    for(i64 i = 60; i >= 0; --i){
        i64 cnt = 0;
        rep(j, b.size()) if(((1LL<<i) & b[j]) && f[j]) ++cnt;
        if(cnt >= K){
            rep(j, b.size()) if(((1LL<<i) & b[j]) == 0) f[j] = false;
            ans += 1LL << i;
        }
    }
    cout << ans << endl;
}

struct IoSetup {
    IoSetup() {
        // cin.tie(nullptr);
        // ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, K, std::move(a));
    return 0;
}
