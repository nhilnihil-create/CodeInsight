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

string calc(string a, char b){
    int tmp = 0;
    rep(i, a.size()){
        if(a[i] < b){
            tmp = i;
            break;
        }
        else{
            tmp = i + 1;
        }
    }
    a.insert(a.begin() + tmp, b);
    return a;
}

string comp(string a, string b){
    if(a.size() < b.size()) return b;
    else if(a.size() > b.size()) return a;

    return max(a, b);
}

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//


    // input
    cout << fixed << setprecision(10);
    int N, M; cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    map<int, char> m;
    vector<int> list{2, 5, 5, 4, 5, 6, 3, 7, 6};
    rep(i, M){
        int first = list[A[i]-1];
        int second = A[i];
        m[first] = max(m[first], char(second + '0'));
    }

    // for(auto x : m){
    //     print(x.first, x.second);
    // }

    string dp[MAX];
    fill(dp, dp+MAX, "");

    rep(i, N+1){
        for(auto x : m){
            int bef = i - x.first;
            if(bef >= 0){
                // print(i, calc(dp[bef], x.second));
                if(bef != 0 && dp[bef].size() == 0) continue;
                dp[i] = comp(dp[i], calc(dp[bef], x.second));
            }
        }
    }

    // rep(i, N+1){
    //     cout << i << ":" <<  dp[i] << endl;
    // }
    // cout << endl;

    print(dp[N]);
    
    return 0;
}
