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


const int MAX_DIGIT = 50;
long long dp[100][2]; // dp[上から i 桁まで][ smaller ]
int main(int argc, const char * argv[]) {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    memset(dp, -1, sizeof(dp)); // DP 配列を -1 で初期化
    dp[0][0] = 0; // 初期条件
    for (int d = 0; d < MAX_DIGIT; ++d) {
        long long mask = 1LL<<(MAX_DIGIT - d - 1);
        
        // A で元々 d 桁目にビットが立っているものの個数
        int num = 0;
        for (int i = 0; i < N; ++i) if (A[i] & mask) ++num;
        
        // X の d 桁目を 0, 1 にしたときのコスト
        long long cost0 = mask * num;
        long long cost1 = mask * (N - num);
        
        // smaller -> smaller
        if (dp[d][1] != -1) {
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1)); // 0 でも 1 でも自在に大きい方
        }
        
        // exact -> smaller
        if (dp[d][0] != -1) {
            if (K & mask) { // K の d 桁目が 1 だったら、X の d 桁目は 0 にする
                chmax(dp[d+1][1], dp[d][0] + cost0);
            }
        }
        
        // exact -> exact (K にぴったり合わせる)
        if (dp[d][0] != -1) {
            if (K & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
            else chmax(dp[d+1][0], dp[d][0] + cost0);
        }
    }
    cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
}  
