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

    REP(i, N){
        cin >> A[i];
        B[i] = A[i] - (i+1);
    }

    sort(B.begin(), B.end());

    ll ans = 0;
    if(N%2 == 1){
        ll c = B[N/2];
        REP(i, N){
            ans += abs(B[i]-c);
        }
    }
    else{
        ll c1 = B[N/2-1];
        ll c2 = B[N/2];
        ll temp1 = 0;
        ll temp2 = 0;
        REP(i, N){
            temp1 += abs(B[i]-c1);
        }
        REP(i, N){
            temp2 += abs(B[i]-c2);
        }
        ans = min(temp1, temp2);
    }
    cout << ans << endl;

    return 0;
}