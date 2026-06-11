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
    int n, a, ans = 23; cin >> n; vector<int> d(13, 0);
    rep(i, n) {
        cin >> a; d[a]++;
        ans = min(ans, a);
    }if (d[0] > 0 || d[12] > 1) {
        cout << 0 << endl;
        return 0;
    }
    req(i, 11) {
        if (d[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }vector<int> b(24, 0);
    b[0] = 1; int f = 0;
    req(i, 12) {
        if (d[i] == 0)continue;
        if (d[i] == 1) {
            if (f) b[24 - i] = 1;
            else b[i] = 1;
            f++; f %= 2;
        }
        else {
            b[24 - i] = 1; b[i] = 1;
        }
    }int cnt = 1;
    req(i, 23) {
        if (!b[i]) cnt++;
        else {
            ans = min(ans, cnt);
            cnt = 1;
        }
    }cout << ans << endl;
}