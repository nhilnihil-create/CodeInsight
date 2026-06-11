#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
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
    vector<int> ans;
    if (N == 3) {
        ans.push_back(2); ans.push_back(5); ans.push_back(63);
    } else if (N == 4) {
        ans.push_back(2); ans.push_back(3); ans.push_back(4); ans.push_back(9);
    } else if (N > 15000) {
        for (int i = 1;i < 30000;++i) {
            if (i%2 == 0) ans.push_back(i);
        }
        if (N%2 == 0) ans.push_back(30000);
        for (int i = 1;i <= 30000;++i) {
            if ((int)ans.size() == N) break;
            if (i%2 != 0 && i%3 == 0) {
                ans.push_back(i);
            }
        }
    } else {
        ans.push_back(3); ans.push_back(9);
        int x;
        if (N%3 == 0) x = N - 1;
        else if (N%3 == 1) x = N - 2;
        else x = N;
        for (int i = 1;i <= 30000;++i) {
            if (i%2 == 0) {
                ans.push_back(i);
                if ((int)ans.size() == x) break;
            }
        }
        if (N%3 == 0) ans.push_back(30000);
        else if (N%3 == 1) ans.push_back(30000),ans.push_back(29994);
    }
    rep(i,N) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}