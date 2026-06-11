#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    string s;
    cin >> s;

    ll j = 0;
    rep(i, 9) {
        if("AKIHABARA"[i] == s[j]) {  // AKIHABARAのi文字目とsのj文字目が一致していたら
            j++;  // jを1増やしてsのj+1文字目を調べる
        }
        else if("AKIHABARA"[i] != 'A') {  // AKIHABARAのi文字目が'A'以外のときにsのj文字目と一致していないならダメ
            out("NO");
            re0;
        }
    }

    if(j == s.size()) {  // sの文字を全て調べていたらok
        out("YES");
    }
    else {  // sの文字を全て調べていなければダメ
        out("NO");
    }
    
    re0;
}