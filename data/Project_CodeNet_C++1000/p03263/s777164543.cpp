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

    vector<vector<ll>> a(H, vector<ll>(W));

    REP(i, H){
        REP(j, W){
            cin >> a[i][j];
        }
    }

    // REP(i, H){
    //     REP(j, W){
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }

    vector<vector<ll>> ans(H*W, vector<ll>(4));
    ll count = 0;
    REP(i, H){
        REP(j, W-1){
            //奇数だった時は右に渡す
            if(a[i][j]%2 != 0){
                a[i][j+1]++;
                // cout << i+1 << " " << j+1 << " " << i+1 << " " << j+2 << endl;
                ans[count][0] = i+1;
                ans[count][1] = j+1;
                ans[count][2] = i+1;
                ans[count][3] = j+2;
                count++;
            }
        }
    }
    REP(i, H-1){
        // 奇数だった時は下に渡す
        if(a[i][W-1]%2 != 0){
            a[i+1][W-1]++;
            // cout << i+1 << " " << W << " " << i+2 << " " << W << endl;
            ans[count][0] = i+1;
            ans[count][1] = W;
            ans[count][2] = i+2;
            ans[count][3] = W;
            count++;
        }
    }
    cout << count << endl;
    for(ll i=0; i<count; i++){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
    }
    return 0;
}