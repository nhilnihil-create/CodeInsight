#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

template<typename T>
using priority_queue_rev = priority_queue<T, vector<T>, greater<T> >;

static const int INTINF = (2147483647 >> 1); // 10^9 + 5000
static const ll LLINF = (9223372036854775807 >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Kunitaka{
    template<
        typename TYPE,
        std::size_t SIZE
    >
    std::size_t array_length(const TYPE (&array)[SIZE])
    {
        return SIZE;
    }

    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
}
using namespace Kunitaka;
namespace Printer{
    void br(){
        cout << endl;
    }

    void loop_cnt(int i){
        cout << "i = " << i << endl;
    }

    void loop_cnt(int i, int j){
        cout << "i = " << i << ", " << "j = " << j << endl;
    }

    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T, class S>
    void print(T x, S y){
        cout << x << "," << y << endl;
    }

    template<class T, class S, class U>
    void print(T x, S y, U z){
        cout << x << "," << y << "," << z << endl;
    }

    template<class T, class S>
    void print(pair<T, S> p){
        cout << p.first << ", " << p.second << endl;
    }

    template<
        typename TYPE,
        std::size_t SIZE
    >
    void print(const TYPE (&array)[SIZE]){
        int lim = array_length(array);
        for(int i=0; i<lim; i++){
            if(i) cout << " ";
            cout << array[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<S> v){
        for(int i=0; i<v.size(); i++){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<vector<S> > vv){
        for(int i=0; i<vv.size(); i++){
            for(int j=0; j<vv[i].size(); j++){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void yesno(bool x){
        if(x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
};
using namespace Printer;

const int nmax = 2001;
ll dp[nmax][nmax];
ll N, Z, W;
vector<ll> a;

// 残りp枚数, q(0 -> x, 1 -> y)
ll solve(ll p, ll q, ll z, ll w){
    if(dp[p][q] != -1){
        return dp[p][q];
    }
    
    ll res = -1;
    if(1 - q == 0){
        res = LLINF;
    }
    else{
        res = 0;
    }
    rep2(i, 1, p){
        ll nz = z;
        ll nw = w;
        if(q == 0){
            nz = a[N - i - 1];
        }
        else{
            nw = a[N - i - 1];
        }
        ll tmp = solve(i, 1 - q, nz, nw);
        // 次がxだったら最小の値
        // 次がyだったら最大の値
        if(1 - q == 0){
            res = min(res, tmp);
        }
        else{
            res = max(res, tmp);
        }
    }

    // 最後まで取る
    if(q == 0){
        z = a[N-1];
    }
    else{
        w = a[N-1];
    }
    if(res == -1 || res == LLINF){
        res = abs(z-w);
    }
    else if(q == 0){
        res = max(res, abs(z - w));
    }
    else{
        res = min(res, abs(z - w));
    }

    // print(p, q, res);
    // print(z, w, abs(z-w));

    return dp[p][q] = res;
}

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//


    // input
    cout << fixed << setprecision(10);
    cin >> N >> Z >> W;
    a.resize(N);
    rep(i, N) cin >> a[i];
    memset(dp, -1, sizeof(dp));

    cout << solve(N, 0, Z, W) << endl;

    
    return 0;
}
