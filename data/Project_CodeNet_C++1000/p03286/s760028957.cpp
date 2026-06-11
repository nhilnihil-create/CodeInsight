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

    vector<ll> Binary(10000);
    ll count = 0;
    ll bina = abs(N);
    for (int i = 0; bina>0 ; i++){
        Binary[i] = bina%2;
        bina = bina/2;
        count++;
    }

    // for(ll i=0; i<count+2; i++){
    //     cout << Binary[i];
    // }
    // cout << endl;

    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    if(N > 0){
        for(ll i=0; i< count; i++){
            if(i%2 == 1){
                if(Binary[i] == 1){
                    Binary[i+1]++;
                }
            }
        }
    }
    if(N < 0){
        for(ll i=0; i< count; i++){
            if(i%2 == 0){
                if(Binary[i] == 1){
                    Binary[i+1]++;
                }
            }
        }
    }
    // for(ll i=0; i<count+2; i++){
    //     cout << Binary[i];
    // }
    // cout << endl;

    for(ll i=0; i<count+10; i++){
        if(Binary[i]==2 && Binary[i+1] == 1){
            Binary[i] = 0;
            Binary[i+1] = 0;
        }
        if(Binary[i]==2){
            Binary[i] = 0;
            Binary[i+1]++;
            Binary[i+2]++;
        }
        if(Binary[i]==3){
            Binary[i] = 1;
            Binary[i+1]++;
            Binary[i+2]++;
        }
        if(Binary[i]==4){
            Binary[i] = 0;
            Binary[i+2]++;
        }
    }
    
    // for(ll i=0; i<count+2; i++){
    //     cout << Binary[i];
    // }
    // cout << endl;

    reverse(Binary.begin(), Binary.end());

    bool check = false;
    for(auto v: Binary){
        if(v == 1){
            check = true;
        }
        if(check){
            cout << v;
        }
    }
    cout << endl;

    return 0;
}