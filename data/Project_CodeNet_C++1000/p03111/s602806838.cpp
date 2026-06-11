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

ll N;
ll A, B, C;
vector<int> l;

int dfs(ll i, ll a, ll b, ll c){
    if(i == N){
        if(min(min(a,b),c) == 0){
            return INF;
        }
        else{
            return abs(a-A) + abs(b-B) + abs(c-C) - 30;
        }
    }
    vector<ll> ans(4);

    ans[0] = dfs(i+1, a, b, c);
    ans[1] = dfs(i+1, a+l[i], b, c)+10;
    ans[2] = dfs(i+1, a, b+l[i], c)+10;
    ans[3] = dfs(i+1, a, b, c+l[i])+10;

    int mx = (int)*min_element(ans.begin(), ans.end());  
    return mx;
}
int main()
{
    cout << fixed << setprecision(15);
    
    cin >> N;
    cin >> A >> B >> C;

    REP(i, N){
        ll t;
        cin >> t;
        l.push_back(t);
    }

    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}