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

    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);

    REP(i, N){
        cin >> A[i];
    }
    REP(i, N){
        cin >> B[i];
    }
    REP(i, N){
        cin >> C[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    REP(i, N){

        vector<ll>::iterator position1;  // auto position; で良い．
        ll id1;

        position1 = upper_bound(C.begin(), C.end(), B[i]);  // 3 を二分探索
        id1 = distance(C.begin(), position1);

        // B より後ろにある数
        ll t1 = N - id1;

        vector<ll>::iterator position2;  // auto position; で良い．
        ll id2;

        position2 = lower_bound(A.begin(), A.end(), B[i]);  // 3 を二分探索
        id2 = distance(A.begin(), position2);
        
        ll t2 = id2;

        ans += t1*t2;

    }

    cout << ans << endl;
    return 0;
}