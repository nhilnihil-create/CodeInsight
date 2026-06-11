#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    string S; cin >> S;
    Pint bw[N + 1];
    bw[0] = mp(0, 0);//black, white
    rep(i, N) {
        bw[i + 1].first = bw[i].first + int(S[i] == '#');
        bw[i + 1].second = bw[i].second + int(S[i] == '.');
    }
    int ans = INF;
    rep(i, N + 1) {
        Pint l = bw[i], r = mp(bw[N].first - bw[i].first, bw[N].second - bw[i].second);
        ans = min(ans, l.first + r.second);
    }
    cout << ans << endl;
}
