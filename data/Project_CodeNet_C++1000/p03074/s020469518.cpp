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
    ll N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<ll> A(3*N+10, 0);

    ll count = 0;
    if(S[0] == '0'){
        A[count] = 0;
        count++;
    }
    
    REP(i, N){
        if(i == 0){
            A[count] = 1; 
            continue;
        }
        if(S[i] == S[i-1]){
            A[count]++;
        }
        else{
            count++;
            A[count] = 1;
        }
    }
    count++;
    // cout << count << endl;

    ll total = 0;
    ll ans = INF;

    for(ll i=0; i<2*K+1; i++){
        total += A[i];
        // cout << A[i] << endl;
    }
    ans = total;
    for(ll i=0; i<N; i=i+2){
        total -= A[i];
        total -= A[i+1];
        total += A[i+2*K+1];
        total += A[i+2*K+2];
        ans = max(ans, total);
    }

    cout << ans << endl;
    return 0;   
}