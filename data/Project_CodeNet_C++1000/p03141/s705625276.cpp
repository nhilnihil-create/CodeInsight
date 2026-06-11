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
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    #define int ll
    int n; cin >> n;
    int a[n], b[n];
    rep(i, n) cin >> a[i] >> b[i];
    Pint dish[n];
    rep(i, n) {
        dish[i].first = a[i] + b[i];
        dish[i].second = i;
    }
    int score_tak = 0, score_aok = 0;
    sort(dish, dish + n, greater<Pint>());
    rep(i, n) {
        if(i % 2 == 0) {
            score_tak += a[dish[i].second];
        }else {
            score_aok += b[dish[i].second];
        }
    }
    cout << score_tak - score_aok << endl;
}
