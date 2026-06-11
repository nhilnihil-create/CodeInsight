#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
#define rep2(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    int ans = 0;
    rep(i,N + 1) {
        vector<int> a(26,0),b(26,0);
        rep(j,i) a[s[j] - 'a'] = 1;
        rep2(j,i,N) b[s[j] - 'a'] = 1;
        int cnt = 0;
        rep(j,26) {
            if (a[j] && b[j]) ++cnt;
        }
        ans = max(ans,cnt);
    }
    cout << ans << '\n';
    return 0;
}