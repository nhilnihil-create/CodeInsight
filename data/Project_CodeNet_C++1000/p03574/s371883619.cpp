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
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);

    REP(i, H){
        cin >> S[i];
    }

    vector<vector<char>> T(H+2, vector<char>(W+2));

    // cout << 1 << endl;

    REP(i, H+2){
        REP(j, W+2){
            if(i == 0 || i== H+1 || j == 0 || j == W+1){
                T[i][j] = '.';
                continue;
            }
            T[i][j] = S[i-1][j-1];
        }
    }

    // cout << 2 << endl;
    for(ll i=1; i<=H; i++){
        for(ll j=1; j<=W; j++){
            if(T[i][j] == '#'){
                cout << '#';
                continue;
            }
            ll temp = 0;
            for(ll ud=-1; ud<=1; ud++){
                for(ll lr=-1; lr<=1; lr++){
                    if(T[i+ud][j+lr] == '#') temp++;
                }
            }
            cout << temp;
        }
        cout << endl;
    }
    return 0;
}