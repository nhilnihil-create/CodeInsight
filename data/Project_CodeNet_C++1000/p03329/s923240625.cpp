#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979

//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
//const int64_t MOD = 1000000007;
//const int64_t INF = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
//#define P pair<int, int>
typedef pair<int, int> P;

int main(){
    int N;
    cin >> N;
    int a = 6, b = 9;
    vector<int> D = {1};
    while(a <= N){
        D.push_back(a);
        a *= 6;
    }
    while(b <= N){
        D.push_back(b);
        b *= 9;
    }
    int s = D.size();
    vector<vector<int>> dp(s + 10, vector<int>(N + 10, INF));
    rep(j, 0, N + 1) dp.at(0).at(j) = j;
    rep(i, 0, s - 1){
        rep(n, 0, N + 1){
            dp.at(i + 1).at(n) = min(dp.at(i).at(n), dp.at(i + 1).at(n));
            if (n >= D.at(i + 1)){
                dp.at(i + 1).at(n) = min(dp.at(i + 1).at(n - D.at(i + 1)) + 1, dp.at(i + 1).at(n));
            }
        }
    }
    cout << dp.at(s - 1).at(N) << endl;
}