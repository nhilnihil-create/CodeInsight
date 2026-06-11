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
    string s;
    cin >> n >> s;
    vector<int> ctr(26, 0);
    rep (i, s.size()) {
        ctr[s[i] - 'a']++;
    }
    ll mod = 1e9 + 7;
    ll ans = 1;
    rep (i, 26) {
        ans *= ctr[i] + 1;
        ans %= mod;
    }
    cout << (ans - 1) % mod << endl;

}