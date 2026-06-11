#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

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

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//


    // input
    cout << fixed << setprecision(10);
    ll N, M; cin >> N >> M;
    vector<ll> A(N), S(N+1);
    rep(i, N){
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }
    rep(i, N+1){
        S[i] %= M;
    }

    // print(S);

    map <ll, ll> m;
    m[0] = 1;
    ll ans = 0;
    rep2(i, 1, N+1){
        // print(S[i], d[0]);
        ll num = S[i];
        if(S[i] == 0){
            ans += m[0];
        }
        else{
            ans += m[num];
        }
        m[S[i]]++;
    }

    print(ans);

    return 0;
}
