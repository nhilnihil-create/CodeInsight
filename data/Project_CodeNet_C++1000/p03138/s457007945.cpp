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

ll pow2(ll a, ll x){
    if(x == 0) return 1;
    else return pow2(a, x-1)*a;
}
int main()
{
    cout << fixed << setprecision(15);
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    REP(i, N){
        cin >> A[i];
    }

    vector<vector<int>> data(N, vector<int>(40));
    data.assign(N, vector<int>(40, 0));

    REP(i, N){
        ll bina = A[i];
        for (int j = 0; bina>0 ; j++){
            data[i][j] = bina%2;
            bina = bina/2;
        }
    }
    
    vector<ll> C(40,0);
    REP(i, N){
        REP(j, 40){
            // cout << data[i][j];
            if(data[i][j] == 1){
                C[j]++;
            }
        }
        // cout << endl;
    }

    // vector<int> KX(40);
    // ll bina = K;
    // int kx_counter = 0;
    // for (int i = 0; bina>0 ; i++){
    //     KX[i] = bina%2;
    //     bina = bina/2;
    //     kx_counter = i;
    // }

    ll ans = 0;
    for(int i=40; i>=0; i--){
        if(C[i] <= N/2){
            ll temp;
            temp = ans + pow2(2, i);
            // cout << i << ":" << temp << endl;
            if(temp > K){
                ans = ans;
            }
            else{
                ans = temp;
            }
        }
    }
    // cout << ans << endl;

    ll ans2 = 0;
    REP(i, N){
        ans2 += ans^A[i];
    }
    cout << ans2 << endl;
    return 0;
}