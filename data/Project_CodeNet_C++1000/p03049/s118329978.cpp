#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    string s[N];
    int ans = 0;
    int a = 0, b = 0, c = 0;
    rep(i, N){
        cin >> s[i];
        if(s[i][0] == 'B' && s[i][sz(s[i])-1] == 'A') c++;
        if(s[i][0] == 'B') b++;
        if(s[i][sz(s[i])-1] == 'A') a++;
        rep(j, sz(s[i])-1){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
        }
    }
    if(a == c && b == c && c > 0) ans += c-1;
    else ans += min({a, b, N-1});
    cout << ans << endl;
}