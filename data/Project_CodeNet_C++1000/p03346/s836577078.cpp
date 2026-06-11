#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);
int dp[200005];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N ;
    vector<int> P(N);
    rep(i,N)cin >> P[i];
    int ans = 0;
    for(int i=0;i<N;i++){
        int p = P[i];
        dp[p] = dp[p-1] + 1;
        chmax(ans,dp[p]);
    }
    cout << N - ans << endl;
}