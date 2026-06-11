#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

int main(int argc, char const *argv[]) {
    string s;
    int n;
    cin >> n >> s;
    int r = 0; int b = 0;
    rep(i,n) {
        if (s[i]=='R') r++;
        else b++;
    }
    if (r>b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}