#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) rep(i, x.size()) cerr << x[i] << (i == x.size() - 1 ? "\n" : " ")
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
const int INF = ((1LL << 30) + (1LL << 29));
const int MOD = 1000000007;

/* 
    D - We Love ABC
*/
//================== INPUT ========================
string S;
//=================================================

//=================================================
void input()
{
    cin >> S;
}
//=================================================

int dp[100003][4] = {}; //dp[i][j]: S[i]まででの照合具合．
// 状態遷移
vector<int> V;
void solve()
{

    int N = S.size();
    V.resize(N);
    rep(i, N)
    {
        V[i] = (S[i] == '?' ? (-1LL) : (S[i] - 'A'));
    }
    // ? : 0, A : 1, B : 2, C : 3.

    // rep(i,N){
    //     cout<<V[i] << (i==N-1 ? "\n" : " ");
    // }

    dp[0][0] = 1;
    rep(i, N)
    {
        rep(j, 4)
        {
            if (V[i] != -1)
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            else
            {
                dp[i+1][j] += dp[i][j]*3;
                dp[i+1][j] %= MOD;
            }
        }
        if (V[i] == -1) {
            dp[i+1][1] += dp[i][0]; dp[i+1][1] %= MOD;
            dp[i+1][2] += dp[i][1]; dp[i+1][2] %= MOD;
            dp[i+1][3] += dp[i][2]; dp[i+1][3] %= MOD;
        }
        else {
            dp[i+1][V[i]+1] += dp[i][V[i]];
            dp[i+1][V[i]+1] %= MOD;
        }
    }
    cout<<dp[N][3]<<endl;
}

//=================================================
signed main()
{
    input();
    solve();
    return 0;
}