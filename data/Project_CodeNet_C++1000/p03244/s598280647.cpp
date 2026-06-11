#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin >> n;
    vector<int> e(100001), o(100001);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        if (i % 2 == 0) {
            e[tmp]++;
        }
        else {
            o[tmp]++;
        }
    }
    vector<int> indices_e(100001), indices_o(100001);
    iota(all(indices_e), 0);
    iota(all(indices_o), 0);

    sort(all(indices_e), [&](int i1, int i2){
        return e[i1] > e [i2];
    });
    sort(all(indices_o), [&](int i1, int i2){
        return o[i1] > o [i2];
    });
    if (indices_e[0] == indices_o[0]) {
        int first = e[indices_e[0]];
        int second = max(e[indices_e[1]], o[indices_o[1]]);
        cout << n - first - second << endl;
    }
    else {
        int first = e[indices_e[0]];
        int second = o[indices_o[0]];
        cout << n - first - second << endl;
    }
}