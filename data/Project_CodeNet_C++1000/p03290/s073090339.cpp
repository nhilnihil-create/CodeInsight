#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
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
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) rbegin(obj), rend(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1LL << 60);
const int INf = 1e9;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    fill((T*)array, (T*)(array + N), val);
}
int main() {
    ll d, g,cnt,ans = INf; cin >> d >> g; vector<ll> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];
    rep(i, (1 << d)) {
        ll sum = 0; cnt = 0;
        rep(j, d) {
            if (i & (1 << j)) {
                sum += c[j] + p[j] * (j + 1) * 100;
                cnt += p[j];
            }
        }
        if (sum >= g) {
            ans = min(ans, cnt);
            continue;
        }
        rrep(j, d) {
            bool f = false;
            if (!(i & (1 << j))) {
                req(k, p[j] - 1) {
                    cnt++; sum += (j + 1) * 100;
                    if (sum >= g) {
                        ans = min(ans, cnt);
                        f = true;
                        break;
                    }
                }
            }
            if (f) break;
        }
    }cout << ans << endl;
}