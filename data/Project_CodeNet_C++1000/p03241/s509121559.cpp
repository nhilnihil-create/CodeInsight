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
    int n, m;
    cin >> n >> m;
    vector<int> divisors;
    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            divisors.push_back(i);
            if (i * i != m) {
                divisors.push_back(m / i);
            }
        }
    }
    int ans = 0;
    for (auto e: divisors) {
        if (1ll * e * n <= 1ll * m) {
            chmax(ans, e);
        }
    }
    cout << ans << endl;
}