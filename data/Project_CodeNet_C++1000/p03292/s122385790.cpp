#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const int mod = 1e5;
const int MAX = 1e7;

int main() {
    vint a(3);
    rep(i,3) cin >> a[i];
    int ans = inf;
    vint p = {0,1,2};
    do {
        int sum = 0;
        rep(i,2) sum += abs(a[p[i]]-a[p[i+1]]);
        chmin(ans,sum);
    } while (next_permutation(p.begin(),p.end()));
    cout << ans << endl;
}