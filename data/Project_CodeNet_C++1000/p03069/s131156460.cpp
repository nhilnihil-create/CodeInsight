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
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 29);
ll h, m, n; string s;
const ll MOD= 1000000007;
const ld PI = acos(-1);
ll sum = 0;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n; vector<int> b(n,0),w(n,0);
    string c;
    cin >> c;
    rep(i, n) {
        if (c[i] != '#') {
            sum++;
        }
    }ll ans = sum;
    rep(i, n) {
        if (c[i] == '.') sum--;
        else sum++;
        ans = min(ans, sum);
    }cout << ans << endl;
}