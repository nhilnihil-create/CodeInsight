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
    vector<int> a(n);
    rep (i, n) {
        cin >> a[i];
    }
    vector<int> ans;
    rep(i, n) {
        for (int j = n - 1 - i; j >= 0; j--) {
            if (j + 1 == a[j]) {
                ans.push_back(j + 1);
                a.erase(a.begin() + j);
                break;
            }
            if (j == 0) {
                cout << -1 << endl;
                exit(0);
            }
        }
    }
    reverse(all(ans));
    rep(i, n) {
        cout << ans[i] << endl;
    }
}