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
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);

    REP(i, X){
        cin >> A[i];
    }
    REP(i, Y){
        cin >> B[i];
    }
    REP(i, Z){
        cin >> C[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    vector<ll> E(min(X, K)*min(Y, K));

    REP(i, min(X, K)){
        REP(j, min(Y, K)){
            E.push_back(A[i] + B[j]);
        }
    }

    sort(E.begin(), E.end(), greater<ll>());

    vector<ll> F(min(min(X, K)*min(Y, K), K)*min(Z, K));
    REP(i, min(min(X, K)*min(Y, K), K)){
        REP(j, min(Z, K)){
            F.push_back(E[i] + C[j]);
        }
    }

    sort(F.begin(), F.end(), greater<ll>());

    REP(i,K){
        cout << F[i] << endl;
    }
    return 0;
}
