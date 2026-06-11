#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

ll dp[100][2];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    for(int i=0;i<100;i++)dp[i][0] = dp[i][1] = -1;
    dp[45][0] = 0;
    for(int d=44;d>=0;d--){
        ll mask = 1LL << d;
        int num = 0;
        for(int i=0;i<N;i++)if(A[i]&mask)num++;

        if(dp[d+1][1]>=0)dp[d][1] = max(dp[d][1],dp[d+1][1] + mask*max(num,N-num));
        if(dp[d+1][0]>=0){
            if(K&(1LL<<d)){
                chmax(dp[d][1],dp[d+1][0] + mask*num);
                chmax(dp[d][0],dp[d+1][0] + mask*(N-num));
            }else{
                chmax(dp[d][0],dp[d+1][0] + mask*num);
            }
        }
    }
    cout << max(dp[0][0],dp[0][1]) << endl;
}