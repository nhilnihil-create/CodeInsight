#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll dp[100010][3];

int main()
{
    cout << fixed << setprecision(15);
    string S;
    cin >> S;

    REP(i, 100010){
        REP(j, 3){
            dp[i][j] = 0;
        }
    }

    ll N = S.length();
    ll third = 1;
    for(ll i=0; i<N; i++){
        if(S[i] == 'A'){
            dp[i+1][0] = dp[i][0] + third;
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = dp[i][2];
        }
        if(S[i] == 'B'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1] + dp[i][0];
            dp[i+1][2] = dp[i][2];
        }
        if(S[i] == 'C'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1];
            dp[i+1][2] = dp[i][2] + dp[i][1];
        }
        if(S[i] == '?'){
            dp[i+1][0] = dp[i][0]*3 + third;
            dp[i+1][1] = dp[i][1]*3 + dp[i][0];
            dp[i+1][2] = dp[i][2]*3 + dp[i][1];
            third *= 3;
            third = third % MOD;
        }

        dp[i+1][0] = dp[i+1][0] % MOD;
        dp[i+1][1] = dp[i+1][1] % MOD;
        dp[i+1][2] = dp[i+1][2] % MOD;
    }
    cout << dp[N][2] << endl;

    return 0;
}