#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9+7;
const ll inf_l = 1e18;
const int MAX = 1e6;

int n;

bool check(vector<string> data, int b) {
    bool ok = true;
    rep(i,n)rep(j,n) {
        if (data[i][(j-b)<0?j-b+n:j-b] != data[j][(i-b)<0?i-b+n:i-b]) {
            ok = false;
        }
    }
    return ok;
}

int main() {
    cin >> n;
    vector<string> data(n);
    rep(i,n) cin >> data[i];
    int ans = 0;
    rep(i,n) if (check(data,i)) ans++;
    ans *= n;
    cout << ans << endl;
}