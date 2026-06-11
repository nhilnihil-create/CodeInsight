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
    ll N, C;
    cin >> N >> C;

    vector<vector<ll>> D(C+1, vector<ll>(C+1));

    for(ll i=1; i<=C; i++){
        for(ll j=1; j<=C; j++){
            cin >> D[i][j];
        }
    }

    map<ll, ll> M0;
    map<ll, ll> M1;
    map<ll, ll> M2;
    for(ll i=1; i<=N; i++){
        for(ll j=1; j<=N; j++){
            ll a;
            cin >> a;
            if((i+j)%3 == 0){
                if(M0.count(a)){
                    M0[a]++;
                }
                else{
                    M0[a] = 1;
                }
            }
            if((i+j)%3 == 1){
                if(M1.count(a)){
                    M1[a]++;
                }
                else{
                    M1[a] = 1;
                }
            }
            if((i+j)%3 == 2){
                if(M2.count(a)){
                    M2[a]++;
                }
                else{
                    M2[a] = 1;
                }
            }
        }
    }

    // cout << "M0" << endl;
    // for (auto iter = M0.begin(); iter != M0.end(); iter++){
    //     cout << iter->first << " " << iter->second << endl;
    // }
    // cout << "M1" << endl;
    // for (auto iter = M1.begin(); iter != M1.end(); iter++){
    //     cout << iter->first << " " << iter->second << endl;
    // }
    // cout << "M2" << endl;
    // for (auto iter = M2.begin(); iter != M2.end(); iter++){
    //     cout << iter->first << " " << iter->second << endl;
    // }

    ll ans = INF;
    for(ll i=1; i<=C; i++){
         for(ll j=1; j<=C; j++){
            for(ll k=1; k<=C; k++){
                if(i==j) continue;
                if(j==k) continue;
                if(k==i) continue;
                // cout<< i << j << k << endl;

                ll temp = 0;
                for (auto iter = M0.begin(); iter != M0.end(); iter++){
                    temp += D[iter->first][i]*iter->second;
                }
                for (auto iter = M1.begin(); iter != M1.end(); iter++){
                    temp += D[iter->first][j]*iter->second;
                }
                for (auto iter = M2.begin(); iter != M2.end(); iter++){
                    temp += D[iter->first][k]*iter->second;
                }
                // cout << temp << endl;
                ans = min(ans, temp);
            }       
        }
    }
    cout << ans << endl;
    return 0;
}