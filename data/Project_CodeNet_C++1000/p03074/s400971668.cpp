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
    ll N, K;
    string S;

    cin >> N >> K;
    cin >> S;

    char now = S[0];
    ll count = 0;
    vector<ll> C;
    if(S[0] == '0'){
        C.push_back(0);
    }
    REP(i, N){
        if(S[i] == now){
            count++;
        }
        else{
            C.push_back(count);
            count = 1;
        }
        now = S[i];
    }
    C.push_back(count);
    if(S[N-1] == '0'){
        C.push_back(0);
    }

    ll L = C.size();
    vector<ll> A(L+1);
    
    A[0] = 0;
    for(ll i=0; i<L; i++){
        A[i+1] = A[i] + C[i];
    }

    // REP(i, L){
    //     cout << T[i] << " " << C[i] << " " << A[i] << endl;
    // }

    ll ans = 0;
    for (ll left = 0; left < L+1; left += 2) {
        ll right = left + K*2+1;
        if (right >= L+1) right = L;
        ans = max(ans, A[right] - A[left]);
    }
    cout << ans << endl;
   
    return 0;
}