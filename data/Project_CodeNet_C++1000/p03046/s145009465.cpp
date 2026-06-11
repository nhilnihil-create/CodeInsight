#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int M, K;
    cin >> M >> K;
    if(K >= 1<<M){
        cout << -1 << endl;
        return 0;
    }
    if(M == 1){
        if(K == 1){
            cout << -1 << endl;
            return 0;
        }
        else{
            cout << 0 << ' ' << 1 << ' ' << 1 << ' ' << 0 << endl;
            return 0;
        }
    }
    vector<int> ans;
    rep(i, 1<<M){
        if(i != K) ans.pb(i);
    }
    ans.pb(K);
    rep3(i, (1<<M)-1, 0){
        if(i != K) ans.pb(i);
    }
    ans.pb(K);
    for(auto &e: ans) cout << e << ' ';
    cout << endl;
}