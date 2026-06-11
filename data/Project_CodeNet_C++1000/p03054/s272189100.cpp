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
        if(x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
};
using namespace Printer;

int main(int argc, const char * argv[]) {
    //提出時、消す----//

    // variable
    bool ans = true;

    // input
    cout << fixed << setprecision(10);
    int H, W, N; cin >> H >> W >> N;
    int sr, sc; cin >> sc >> sr;
    string S, T; cin >> S >> T;
    reverse(ALL(S)); reverse(ALL(T));

    // solve
    pair<int, int> f = make_pair(1, W);
    rep(i, S.size()){
        if(T[i] == 'R') f.first = max(1, f.first - 1);
        if(T[i] == 'L') f.second = min(W, f.second + 1);
        if(S[i] == 'R') f.second--;
        if(S[i] == 'L') f.first++;
        if(f.first > f.second){
            yesno(false);
            return 0;
        }
    }
    // print(f);

    if(sr < f.first || f.second < sr) ans = false;

    f = make_pair(1, H);
    // br();
    rep(i, S.size()){
        if(T[i] == 'U') f.second = min(H, f.second + 1);
        if(T[i] == 'D') f.first = max(1, f.first - 1);
        if(S[i] == 'U') f.first++;
        if(S[i] == 'D') f.second--;
        if(f.first > f.second){
            yesno(false);
            return 0;
        }
        // print(f);
    }
    // br();
    // print(f);

    if(sc < f.first || f.second < sc) ans = false;

    yesno(ans);

    // yesno(ans);
    
    return 0;
}
