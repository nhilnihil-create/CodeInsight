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
#define rreq(i,n) for(ll i = n;i >= 1;i--)
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
    string s; cin >> s;
    int ans = s.size(),n = s.size();
    req(i, n - 1) {
        if (s[i-1] != s[i]) {
            ans = min(ans, max(i, n - i));
        }
    }cout << ans << endl;
}