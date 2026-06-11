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
#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    string N; cin >> N;
    int ans = 0;
    bool flg1 = true;
    rep(i, N.size() - 1) {
        ans += 9;
        if(N[i + 1] != '9') flg1 = false;
    }
    bool flg = true;
    rep(i, N.size()) if(N[i] != '9') flg = false;
    ans += ((flg) ? 9 : (N[0] - '0') - ((!flg1) ? 1 : 0));
    if(N.size() == 1) ans = N[0] - '0';
    cout << ans << endl;
}
