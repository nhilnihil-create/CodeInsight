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

using Data = pair<ll, vector<ll>>;

int main()
{
    cout << fixed << setprecision(15);
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    
    REP(i, X){
        cin >> A[i];
    }
    REP(i, Y){
        cin >> B[i];
    }
    REP(i, Z){
        cin >> C[i];
    }

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());
    
    priority_queue<Data> que;
    set<Data> se;

    que.push(Data(A[0] + B[0] + C[0], vector<ll>({0, 0, 0})));

    for(ll k=0; k<K; k++){
        auto c = que.top();que.pop();
        cout << c.first << endl;
        // cout << c.second[0] << " " << c.second[1] << " " << c.second[2] << endl;

        ll a1 = c.second[0];
        ll b1 = c.second[1];
        ll c1 = c.second[2];
        if(a1+1 < X){
            ll sum = c.first - A[a1] + A[a1+1];
            auto num = c.second;
            num[0]++;
            auto d = Data(sum, num);
            
            // すでに push されたもの以外
            if (!se.count(d)) se.insert(d), que.push(d);
        }
        if(b1+1 < Y){
            ll sum = c.first - B[b1] + B[b1+1];
            auto num = c.second;
            num[1]++;
            auto d = Data(sum, num);
            
            // すでに push されたもの以外
            if (!se.count(d)) se.insert(d), que.push(d);
        }
        if(c1+1 < Z){
            ll sum = c.first - C[c1] + C[c1+1];
            auto num = c.second;
            num[2]++;
            auto d = Data(sum, num);
            
            // すでに push されたもの以外
            if (!se.count(d)) se.insert(d), que.push(d);
        }
    }
    return 0;
}