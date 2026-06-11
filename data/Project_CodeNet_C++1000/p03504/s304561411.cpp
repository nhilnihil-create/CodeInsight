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
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

struct data{int s, t, c;};

int main() {
    int n, C; cin >> n >> C;
    vector<data> sec;
    vector<map<int,int>> ct(C);
    rep(i,n) {
        int s, t, c; cin >> s >> t >> c;
        c--;
        ct[c][s]++; ct[c][t]++;
    }
    vint c(MAX+5);
    rep(i,C) {
        int flag = 1;
        for (P x : ct[i]) {
            if (x.second == 2) continue;
            if (flag == 1) c[x.first-1]++;
            else c[x.first]--;
            flag *= -1;
        }
    }
    vint cover(MAX+5);
    cover[0] = c[0];
    REP(i,MAX+5) cover[i] += cover[i-1]+c[i];
    int ans = 0;
    rep(i,MAX+5) ans = max(ans,cover[i]);
    cout << ans << endl;
}