#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);
ll dp[105][2]; 
// dp[a][b]:= 左から a bitまで見て 
// K以下が b=0:確定していない b=1確定している
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    rep(i,105)dp[i][0] = dp[i][1] = -1;
    dp[50][0] = 0;
    for(int bit=49;bit>=0;bit--){ // bit bit 目を考える
        ll mask = (1LL<<bit);
        ll num = 0; // bit bit 目が立っている A[i] の個数
        rep(i,N)if(A[i]&mask)num++; // もしもbitが立っていたらnumを加算

        if(dp[bit+1][1]>=0)dp[bit][1] = dp[bit+1][1] + mask*max(num,N-num);
        //if(dp[bit+1][0]>=0){
            if(K&mask){
                // もしも K の bit bit 目が 1 だったならば
                // 1を選んだ場合
                dp[bit][0] = dp[bit+1][0] + mask*(N-num);
                // 0を選んだ場合
                chmax(dp[bit][1],dp[bit+1][0] + mask*num);
            }else{
                dp[bit][0] = dp[bit+1][0] + mask*num; 
            }
        //}
    }
    cout << max(dp[0][0],dp[0][1]) << endl;
}