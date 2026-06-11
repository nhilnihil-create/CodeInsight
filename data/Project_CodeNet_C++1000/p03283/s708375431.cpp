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
    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<ll>> A(N+1, vector<ll>(N+1, 0));
    REP(i, M){
        ll l;
        ll r;
        cin >> l >> r;
        A[l][r]++;
    }

    // REP(i, N){
    //     REP(j, N){
    //         cout << A[i][j];
    //     }
    //     cout << endl;
    // }

    // 累積カウント用
    vector<vector<ll>> B(N+1, vector<ll>(N+1, 0));
    REP(i, N+1){
        REP(j, N+1){
            if(j == 0){
                B[i][j] = A[i][j];
            }
            else{
                B[i][j] = B[i][j-1] + A[i][j];
            }
        }
    }

    REP(i, Q){
        ll p,q;
        cin >> p >> q;

        ll ans = 0;
        for(ll j=p; j<=q; j++){
            ans += B[j][q] - B[j][p-1];
        }
        cout << ans << endl;
    }
    return 0;
}