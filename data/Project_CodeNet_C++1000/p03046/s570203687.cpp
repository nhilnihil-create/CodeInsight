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

int main()
{
    cout << fixed << setprecision(15);
    
    ll M, K;
    cin >> M >> K;

    // M=0のときはK=0のみが解となる
    if(M == 0){
        if(K == 0){
            cout << 0 << " " << 0 << endl;
            return 0;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    // M=1のときはK=0のみが解となる
    if(M == 1){
        if(K == 0){
            cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
            return 0;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(K >= pow(2, M)){
        cout << -1 << endl;
        return 0;
    }

    for(ll i=0; i<pow(2,M); i++){
        if(i == K) continue;
        cout << i << " ";
    }
    cout << K << " ";
     for(ll i=pow(2,M) - 1; i>=0; i--){
        if(i == K) continue;
        cout << i << " ";
    }
    cout << K << endl;;

    return 0;
}