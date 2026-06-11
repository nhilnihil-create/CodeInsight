#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n-1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e18;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MOD = 1e9+7;
int main(void) {
    ll n,k; cin >> n>>k; vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll val = 0;
    rrep(i, 41) {
        int set = 0;
        rep(j, n) {
            if ((a[j]>> i)&1)set++;
        }if (n - set > set && val + (1LL << i) <= k)val += (1LL << i);
    }ll ans = 0;
    rep(i, n) {
        ans += (a[i] ^ val);
    }cout << ans << endl;
}