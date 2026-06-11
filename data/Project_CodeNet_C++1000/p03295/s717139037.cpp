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
ll k, m, n,h,w,v;
const ll MOD= 1000000007;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n >> m; vector<pair<int, int>> a(m);
    rep(i, m) {
        cin >> h >> w;
        a[i] = make_pair(w, h);
    }
    int cnt = 1;
    sort(ALL(a)); k = a[0].first;
    req(i, m - 1) {
        if (k <= a[i].second) {
            cnt++; k = a[i].first;
        }
    }cout << cnt << endl;
}