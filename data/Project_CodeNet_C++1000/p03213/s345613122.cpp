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

    vector<ll> A(N+1, 0);

    for(ll i=1; i<=N; i++){
        ll t = i;
        for(ll j=2; j<=t; j++){
            while(t%j ==0){
                t = t/j;
                A[j]++;
            }
        }
    }
    ll a=0;
    ll b=0;
    ll c=0;
    ll d=0;
    ll e=0;

    for(ll i=2; i<=N; i++){
        // cout << A[i] << endl;
        if(A[i] >= 2) a++;
        if(A[i] >= 4) b++;
        if(A[i] >= 14) c++;
        if(A[i] >= 24) d++;
        if(A[i] >= 74) e++;
    }

    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;
    // cout << d << endl;
    // cout << e << endl;

    ll ans = 0;

    ans += b*(b-1)/2 * (a-2);
    ans += d * (a-1);
    ans += c * (b-1);
    ans += e;

    cout << ans << endl;
    return 0;
}