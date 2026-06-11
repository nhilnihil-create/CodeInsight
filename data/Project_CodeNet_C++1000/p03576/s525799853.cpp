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
const unsigned long long LINF = 1e19;

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
    vector<ll> y(N);
    vector<P> p(N);
    REP(i, N){
        cin >> x[i] >> y[i];
        p[i].first = x[i];
        p[i].second = y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    unsigned long long ans = LINF;
    for(ll xmin=0; xmin<N-1; xmin++){
        for(ll xmax=xmin+1; xmax<N; xmax++){
            for(ll ymin=0; ymin<N-1; ymin++){
                for(ll ymax=ymin+1; ymax<N; ymax++){
                    ll count = 0;
                    REP(i, N){
                        if(x[xmin] <= p[i].first && p[i].first <= x[xmax]){
                            if(y[ymin] <= p[i].second && p[i].second <= y[ymax]){
                                count++;
                            }
                        }
                    }
                    if(count >= K){
                        unsigned long long x_dif = x[xmax]-x[xmin];
                        unsigned long long y_dif = y[ymax]-y[ymin];
                        ans = min(ans, x_dif*y_dif);
                        // cout << (x[xmax]-x[xmin]) << " " << (y[ymax]-y[ymin]) << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}