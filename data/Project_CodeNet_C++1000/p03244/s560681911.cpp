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
    ll N;
    cin >> N;

    vector<ll> v(N);

    REP(i, N){
        cin >> v[i];
    }

    map<ll, ll> A;
    map<ll, ll> B;

    REP(i, N){
        if(i%2 == 0){
            A[v[i]]++;
        }
        else{
            B[v[i]]++;
        }
    }

    ll amax = 0;
    ll bmax = 0;

    ll atop = 0;
    ll asecond = 0;
    ll btop = 0;
    ll bsecond = 0;

    for(auto iter=A.begin(); iter!=A.end(); iter++){
        if(amax <= iter->second){
            amax = iter->second;
            atop = iter->first;
        }
    }
    amax = 0;
    for(auto iter=A.begin(); iter!=A.end(); iter++){
        if(iter->first == atop) continue;
        if(amax <= iter->second){
            amax = iter->second;
            asecond = iter->first;
        }
    }

    for(auto iter=B.begin(); iter!=B.end(); iter++){
        if(bmax <= iter->second){
            bmax = iter->second;
            btop = iter->first;
        }
    }
    bmax = 0;
    for(auto iter=B.begin(); iter!=B.end(); iter++){
        if(iter->first == btop) continue;
        if(bmax <= iter->second){
            bmax = iter->second;
            bsecond = iter->first;
        }
    }

    if(atop != btop){
        cout << N - A[atop] - B[btop] << endl;
        return 0;
    }
    if(A[atop] > B[btop]){
        cout << (N/2-A[atop]) + (N/2-B[bsecond]) << endl;
    }
    else if(A[atop] < B[btop]){
        cout << (N/2-A[asecond]) + (N/2-B[btop]) << endl;
    }
    else{
        cout << (N/2-A[atop]) + (N/2-max(A[asecond], B[bsecond])) << endl;;
    }
    return 0;
}