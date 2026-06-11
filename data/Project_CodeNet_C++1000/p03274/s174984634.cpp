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

    vector<ll> x(N);
    REP(i, N){
        cin >> x[i];
    }

    vector<ll> M;
    vector<ll> P;

    REP(i, N){
        if(x[i]<0) M.push_back(-x[i]);
        else P.push_back(x[i]);
    }

    ll MS = M.size();
    ll PS = P.size();

    sort(M.begin(), M.end());
    
    vector<ll> TM(MS+1);
    vector<ll> TP(PS+1);

    REP(i, MS+1){
        if(i==0) TM[i] = 0;
        else{
            TM[i] = M[i-1];
        }
        // cout << TM[i] << endl;
    }
    // cout << endl;

    REP(i, PS+1){
        if(i==0) TP[i] = 0;
        else{
            TP[i] = P[i-1];
        }
        // cout << TP[i] << endl;
    }

    ll ans = INF;
    for(ll i=0; i<=K; i++){
        ll left = i;
        ll right = K-i;
        if(i > MS) continue;
        if(K-i > PS) continue;

        ans = min(ans, TM[left] + TP[right]*2);
        ans = min(ans, TM[left]*2 + TP[right]);
    }
    cout << ans << endl;
    return 0;
}