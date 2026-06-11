#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define ALL(a) a.begin(),a.end()
#define PI  acos(-1)
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
typedef long double ld;
int main() {
    int n, m, k, a, ans = 0; cin >> n >> m;
    vector<vector<int>> G(11,vector<int>(11,0));
    rep(i, m) {
        cin >> k;
        rep(j, k) {
            cin >> a; a--;
            G[i][a] = 1;
        }
    }vector<int> p(m);
    rep(i, m) cin >> p[i];
    rep(i, 1 << n) {
        int u = 0;
        rep(j, m) {
            int cnt = 0;
            rep(k, n) {
                if (G[j][k] && i & (1 << k))cnt++;
            }
            if (cnt % 2 == p[j]) u++;
        }
        if (u == m) ans++;
    }cout << ans << endl;
}