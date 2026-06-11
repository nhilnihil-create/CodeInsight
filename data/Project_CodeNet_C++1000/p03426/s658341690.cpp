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
    ll H, W, D;
    cin >> H >> W >> D;

    vector<vector<ll>> A(H+1, vector<ll>(W+1));
    vector<P> B(H*W+1);
    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            cin >> A[i][j];
            B[A[i][j]].first = i;
            B[A[i][j]].second = j;
        }
    }

    // その数に到達するまでの数
    vector<ll> C(H*W+1,0);

    for(ll i=1; i<=D; i++){
        for(ll j=i; j<=H*W; j=j+D){
            if(j<=D){
                C[j] = 0;
                continue;
            }
            ll x1 = B[j].first;
            ll y1 = B[j].second;
            ll x2 = B[j-D].first;
            ll y2 = B[j-D].second;
            C[j] = C[j-D] + abs(x1-x2) + abs(y1-y2);
        }
    }

    ll Q;
    cin >> Q;

    REP(i, Q){
        ll L;
        ll R;
        cin >> L >> R;
        cout << C[R] -C[L] << endl;
    }

    return 0;
}