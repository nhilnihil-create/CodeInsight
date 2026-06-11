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
const ll LINF = 1e14;

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

    ll A, B, Q;
    cin >> A >> B >> Q;

    vector<ll> S(A+2);
    vector<ll> T(B+2);
    vector<ll> X(Q);

    REP(i, A){
        cin >> S[i+1];
    }
    S[0] = -LINF;
    S[A+1] = LINF;
    REP(i, B){
        cin >> T[i+1];
    }
    T[0] = -LINF;
    T[B+1] = LINF;
    REP(i, Q){
        cin >> X[i];
    }

    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    REP(i, Q){
        vector<ll>::iterator iter_lower_S;
        iter_lower_S = lower_bound(S.begin(), S.end(),X[i]);
        ll idx_lower_S = distance(S.begin(), iter_lower_S); 
        ll SL, SR;
        if(S[idx_lower_S] == X[i]){
            SL = 0;
            SR = 0;
        }
        else{
            SL = S[idx_lower_S-1];
            SR = S[idx_lower_S];
        }

        vector<ll>::iterator iter_lower_T;
        iter_lower_T = lower_bound(T.begin(), T.end(),X[i]);
        ll idx_lower_T = distance(T.begin(), iter_lower_T); 
        ll TL, TR;
        if(T[idx_lower_T] == X[i]){
            TL = 0;
            TR = 0;
        }
        else{
            TL = T[idx_lower_T-1];
            TR = T[idx_lower_T];
        }

        ll ans1, ans2, ans3, ans4;
        ans1 = max(abs(SL-X[i]), abs(TL-X[i]));
        ans2 = max(abs(SR-X[i]), abs(TR-X[i]));
        ans3 = min(abs(SL-X[i]), abs(TR-X[i]))*2 + max(abs(SL-X[i]), abs(TR-X[i]));
        ans4 = min(abs(SR-X[i]), abs(TL-X[i]))*2 + max(abs(SR-X[i]), abs(TL-X[i]));

        cout << min(min(ans1, ans2), min(ans3, ans4)) << endl;
    }
    return 0;
}