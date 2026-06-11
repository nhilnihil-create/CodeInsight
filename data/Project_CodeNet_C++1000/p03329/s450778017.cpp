#include <bits/stdc++.h>
#define rep(i, z, n) for(int64_t i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979
//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
//const int64_t MOD = 1000000007;
//const int64_t INF = 998244353;
using namespace std;
typedef pair<int64_t, int64_t> P;

int main(){
    int N;
    cin >> N;
    vector<int> dp(N + 100, INF);
    dp.at(0) = 0;
    rep(n, 1, N + 1){
        for(int pow6 = 1; pow6 <= n; pow6 *= 6){
            dp.at(n) = min(dp.at(n), dp.at(n - pow6) + 1);
        }
        for(int pow9 = 1; pow9 <= n; pow9 *= 9){
            dp.at(n) = min(dp.at(n), dp.at(n - pow9) + 1);
        }
    }
    cout << dp.at(N) << endl;
}