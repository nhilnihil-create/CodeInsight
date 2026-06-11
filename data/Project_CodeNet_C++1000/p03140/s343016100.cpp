#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
    int n; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    rep(i,n){
        if (a.at(i) == b.at(i)){
            if (b.at(i) != c.at(i)) ans++;
        }
        else if (a.at(i) == c.at(i) || b.at(i) == c.at(i)) ans++;
        else ans += 2;
    }
    cout << ans << endl;
}