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
    return a/gcd(a, b) * b;
}

vector<ll> binary_count (ll n) {
    vector<ll> ret;
    ll target = n+1;

    ll now = 2;
    while(now/2 <= target){
        if(now == 2){
            ret.push_back((target/2)%2);
            now *= 2;
            continue;
        }
        // cout << ((target/now)-(now/2) + now+1)%2 << endl;
        ret.push_back((max(0LL,(target%now)-(now/2)))%2);
        now *= 2;
    }
    
    return (ret);
}

ll powll(ll a, ll x){
    if(x == 0) return 1;
    else return powll(a, x-1)*a;
}

int main()
{
    cout << fixed << setprecision(15);
    ll A, B;
    cin >> A >> B;

    vector<ll> Aans = binary_count(A-1);
    vector<ll> Bans = binary_count(B);

    // ll Asize = Aans.size();
    // ll Bsize = Bans.size();
    // for(auto iter: Aans){
    //     cout << iter;
    // }
    // cout << endl;
    
    // reverse(Aans.begin(), Aans.end());
    // reverse(Bans.begin(), Bans.end());

    ll Aans10 = 0;
    for(ll i=0; i<Aans.size(); i++){
        if(Aans[i] == 1){
            Aans10 += powll(2, i);
        }
    }
    // cout << Aans10 << endl;
    ll Bans10 = 0;
    for(ll i=0; i<Bans.size(); i++){
        if(Bans[i] == 1){
            Bans10 += powll(2, i);
        }
    }
    // cout << Bans10 << endl;

    cout << (Aans10 ^ Bans10) << endl;
    return 0;
}