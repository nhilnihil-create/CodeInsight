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

// pairsをsecond優先キーとして降順ソート
bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first > b.first;
    }
}
int main()
{
    cout << fixed << setprecision(15);
    ll N, H;
    cin >> N >> H;

    vector<P> A(N);

    ll amax = 0;
    ll aid = 0;

    REP(i, N){
        cin >> A[i].first >> A[i].second;

        if(A[i].first > amax){
            amax = A[i].first;
            aid = i;
        }
    }

    sort(A.begin(), A.end(), compare_by_b);

    // REP(i, N){
    //     cerr << A[i].second << endl;
    // }
    ll ans = 0;

    REP(i, N){
        // いい感じの投げるやつがもうないとき
        if(A[i].second <= amax) break;

        H -= A[i].second;
        ans++;
        if(H <= 0){
            cout << ans << endl;
            return 0;
        }
    }
    // cerr << ans << endl;
    if(H > 0){
        ans += (H-1)/amax + 1;
    }
    // while(H>0){
    //     if(H <= amax || H <= A[aid].second){
    //         ans++;
    //         break;
    //     }
    //     H -= amax;
    //     ans++;
    // }
    cout << ans << endl;
    
    return 0;
}