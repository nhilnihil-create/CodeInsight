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
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll p = 4 * h * n - N * n - N * h;
            if (p > 0 && N * h * n % p == 0) {
                ll w = N * h * n / p;
                printf("%d %d %d\n", h, n, w);
                exit(0);
            }
        }
    }
}