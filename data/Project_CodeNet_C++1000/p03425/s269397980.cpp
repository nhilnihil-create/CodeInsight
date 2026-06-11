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

    vector<string> S(N);

    REP(i, N){
        cin >> S[i];
    }

    vector<ll> A(5, 0);
    REP(i, N){
        if(S[i][0] == 'M') A[0]++;
        if(S[i][0] == 'A') A[1]++;
        if(S[i][0] == 'R') A[2]++;
        if(S[i][0] == 'C') A[3]++;
        if(S[i][0] == 'H') A[4]++;
    }

    ll ans = 0;
    for(ll i=0; i<3; i++){
        for(ll j=i+1; j<4; j++){
            for(ll k=j+1; k<5; k++){
                ans += A[i]*A[j]*A[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}