#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;
#define REP(i, n)  for(int i=0;i<(int)(n);++i)
#define FOR(i, b, n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define SS size()
#define ST first
#define ND second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
int n;
ll C;
vector<pll> su;

ll solve() {
   vl back(n+1); back[n] = 0;
   ll sum = 0;
   for(int i=n-1; i>=0; i--) {
       sum += su[i].ND;
       back[i] = max(back[i+1], sum - (C - su[i].ST));
   }
   sum = 0;
   ll ans = 0;
   for(int i=0; i<n; i++) {
       sum += su[i].ND;
       amax(ans, sum - su[i].ST);  //single pass
       amax(ans, sum - 2 * su[i].ST + back[i+1]); //right-back-left
   }
   return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin >> n >> C;
    ll x, v;
    ll ans = 0;
    REP(i,n) {cin >> x >> v; su.push_back({x,v});}
    sort(ALL(su));
    ans = solve();
    REP(i,n) su[i].ST = C - su[i].ST;
    sort(ALL(su));
    amax(ans, solve());
    cout << ans << endl;
}




















