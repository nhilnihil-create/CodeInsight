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
    ll N; cin >> N;
    for(ll i = 1; i <= 3500; ++i) {
        for(ll j = 1; j <= 3500; ++j) {
            if((4 * i * j - N * i - N * j) != 0) {
                if((N * i * j) % (4 * i * j - N * i - N * j) == 0 && (N * i * j) / (4 * i * j - N * i - N * j) > 0) {
                    cout << i << ' ' << j << ' ' << (N * i * j) / (4 * i * j - N * i - N * j) << endl;
                    return 0;
                }
            }
        }
    }
}
