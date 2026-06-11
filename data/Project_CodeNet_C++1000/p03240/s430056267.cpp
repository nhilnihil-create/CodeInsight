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

bool compare_by_a(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    return get<2>(a) > get<2>(b);
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    vector<tuple<ll, ll, ll> > t(N);
    
    REP(i, N){
        ll x, y, h;
        cin >> x >> y >> h;
        get<0>(t[i]) = x;
        get<1>(t[i]) = y;
        get<2>(t[i]) = h;
    }

    sort(t.begin(), t.end(), compare_by_a);

    // REP(i, N){
    //     cout << get<0>(t[i]) << " " << get<1>(t[i]) << " " << get<2>(t[i]) << endl;
    // }

    for(ll xi=0; xi<=100; xi++){
        for(ll yi=0; yi<=100; yi++){
            ll H = 0;
            for(ll i=0; i<N; i++){
                if(i==0){
                    H = get<2>(t[i]) + abs(get<0>(t[i]) - xi) + abs(get<1>(t[i]) - yi);
                }
                else{
                    if(get<2>(t[i]) > 0){
                        ll temp;
                        temp = get<2>(t[i]) + abs(get<0>(t[i]) - xi) + abs(get<1>(t[i]) - yi);
                        if(temp != H) break;
                    }
                    else{
                        ll temp;
                        temp = get<2>(t[i]) + abs(get<0>(t[i]) - xi) + abs(get<1>(t[i]) - yi);
                        if(H > temp) break;
                    }
                }
                if(i== N-1){
                    cout << xi << " " << yi << " " << H << endl;
                }
            }
        }
    }
    return 0;
}