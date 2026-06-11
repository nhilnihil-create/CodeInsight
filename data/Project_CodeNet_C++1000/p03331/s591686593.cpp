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
//#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int digitSum(int i) {
    int ret = 0;
    while(i > 0) {
        ret += i % 10;
        i /= 10;
    }
    return ret;
}

int main() {
    int N; cin >> N;
    int ans = INF;
    for(int i = 1; i <= (N + 1) / 2; ++i) {
        int j = N - i;
        int res = digitSum(i) + digitSum(j);
        ans = min(ans, res);
    }
    cout << ans << endl;
}
