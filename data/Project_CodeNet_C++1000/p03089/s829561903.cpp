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
    int N; cin >> N;
    vector<int> b(N); rep(i, N) cin >> b[i], --b[i];
    vector<int> ans;
    rep(i, N) {
        bool ok = false;
        for(int j = b.size() - 1; j >= 0; --j) {
            if(j == b[j]) {
                ok = true;
                ans.pb(j + 1);
                b.erase(b.begin() + j);
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(all(ans));
    rep(i, ans.size())cout << ans[i] << endl;
}
