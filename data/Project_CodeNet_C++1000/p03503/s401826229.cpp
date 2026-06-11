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

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    vector<vector<ll>> F(N, vector<ll>(10));
    vector<vector<ll>> P(N, vector<ll>(11));

    REP(i, N){
        REP(j, 10){
            cin >> F[i][j];
        }
    }

    REP(i, N){
        REP(j, 11){
            cin >> P[i][j];
        }
    }

    ll n = 10;
    ll ans = -1*INF;
    for (ll bit = 0; bit < (1<<n); ++bit){

        // 一つも選択しない場合はなし
        if(bit == 0) continue;

        // Cを数えていく
        vector<ll> C(N, 0);
        for (ll i = 0; i < n; ++i) {
            if (bit & (1<<i)){
                REP(j, N){
                    C[j] += F[j][i];
                }
            }
        }
        ll temp = 0;
        
        // この選択での値を保存
        REP(j, N){
            temp += P[j][C[j]];
        }

        ans = max(ans, temp);
        
    }
    cout << ans << endl;
    return 0;
}