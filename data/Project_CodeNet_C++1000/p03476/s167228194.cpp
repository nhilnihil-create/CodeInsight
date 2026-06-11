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

// map<ll, ll> prime_factor(ll n) {
//   map<ll, ll> ret;
//   for(ll i = 2; i * i <= n; i++) {
//     while(n % i == 0) {
//       ret[i]++;
//       n /= i;
//     }
//   }
//   if(n != 1) ret[n] = 1;
//   return ret;
// }

bool prime_check(ll n) {
//   map<ll, ll> ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
        return false;
    }
  }
//   if(n != 1) ret[n] = 1;
  return true;
}


int main()
{
    cout << fixed << setprecision(15);
    ll Q;
    cin >> Q;

    ll N = 100000;

    vector<bool> Prime(N+1, false);

    for(ll i=2; i<=N; i++){
        Prime[i] = prime_check(i);
    }

    // for(ll i=0; i<=N; i++){
    //     cout << i << " " << Prime[i] << endl;
    // }

    vector<ll> A(N+1, 0);
    for(ll i=1; i<=N; i++){
        if(i%2 == 0){
            A[i] = A[i-1];
            continue;
        }
        if(Prime[i] && Prime[(i+1)/2]){
            A[i] = A[i-1] + 1;
        }
        else{
            A[i] = A[i-1];
        }
    }

    REP(i, Q){
        ll left, right;
        cin >> left >> right;

        cout << A[right]- A[left-1] << endl;

    }
    return 0;
}