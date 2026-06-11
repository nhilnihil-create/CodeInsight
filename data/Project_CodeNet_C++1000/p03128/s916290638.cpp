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

ll num(ll a){
    if(a == 1){
        return 2;
    }
    if(a == 2){
        return 5;
    }
    if(a == 3){
        return 5;
    }
    if(a == 4){
        return 4;
    }
    if(a == 5){
        return 5;
    }
    if(a == 6){
        return 6;
    }
    if(a == 7){
        return 3;
    }
    if(a == 8){
        return 7;
    }
    if(a == 9){
        return 6;
    }
    else{
        return INF;
    }
}
int main()
{
    cout << fixed << setprecision(15);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(M);

    REP(i, N){
        cin >> A[i];
    }
    
    vector<ll> dp(N+1, -INF);
    dp[0] = 0;

    for(ll i=1; i<=N; i++){
        ll t_max = -INF;
        REP(j, M){
            if(i-num(A[j]) < 0) continue;
            t_max = max(t_max, dp[i-num(A[j])] + 1); 
        }
        dp[i] = t_max;
    }

    ll digit = dp[N];


    sort(A.begin(), A.end(), greater<int>());

    REP(i, digit){
        for(auto v: A){
            if(N - num(v) < 0) continue;
            if(dp[N - num(v)] == dp[N]-1){
                // cout << "N:" <<  N << endl;
                cout << v;
                N = N - num(v);
                break;
            }
        }
    }
    cout << endl;

    return 0;
}