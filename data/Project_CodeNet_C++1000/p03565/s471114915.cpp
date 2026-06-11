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
    string S, T;
    cin >> S >> T;

    ll SL = S.length();
    ll TL = T.length();

    if(SL < TL){
        cout << "UNRESTORABLE" << endl;
        return 0; 
    }
    ll minid = -1;
    ll minl = INF;
    REP(i, SL-TL+1){
        bool flag = true;
        ll temp = 0;
        REP(j, TL){
            if(S[i+j] == '?'){
                temp++;
                continue;
            }
            if(S[i+j] != '?' && S[i+j] != T[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            // if(temp <= minl){
            //     minl = temp;
            //     minid = i;
            // }
            minid = i;
            minl = temp;
        }
    }
    if(minl == INF){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for(ll i=0; i<minid; i++){
        if(S[i] == '?'){
            cout << 'a';
        }
        else{
            cout << S[i];
        }
    }
    
    cout << T;
    
    for(ll i=minid+TL; i<SL; i++){
        if(S[i] == '?'){
            cout << 'a';
        }
        else{
            cout << S[i];
        }
    }
    cout << endl;
    
    return 0;
}