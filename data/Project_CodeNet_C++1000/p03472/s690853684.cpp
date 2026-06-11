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
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());

    int ctr = 0;
    rep (i, n) {
        if (b[i] <= a[0]) {
            break;
        }
        h -= b[i];
        ctr++;
        if (h <= 0) {
            cout << ctr << endl;
            exit(0);
        }
    }
    cout << ctr + (h + a[0] - 1) / a[0] << endl;
}