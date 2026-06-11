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
const ll LLINF = 1e18;
#define Pint pair<ll, ll>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    ll a[N], b[N];
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    ll cnt1 = 0, cnt2 = 0;
    rep(i, N) {
        if(b[i] < a[i]){
            cnt2 += (a[i] - b[i]);
        } else if(a[i] < b[i]) {
            cnt1 += (b[i] - a[i]) / 2;
        }
    }
    if(cnt2 <= cnt1) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
