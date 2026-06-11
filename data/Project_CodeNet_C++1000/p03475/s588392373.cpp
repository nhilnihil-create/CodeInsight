#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(long long int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll inf = (1LL << 60);
const int MOD = 1000000007;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    int n; cin >> n; vector<ll> c(n), s(n), f(n);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
    rep(i, n) {
        int t = 0;
        for (int j = i; j < n - 1;j++) {
            if (t < s[j]) t = s[j];
            else if (t % f[j] == 0);
            else t = t + f[j] - (t % f[j]);
            t += c[j];
        }
        cout << t << endl;
    }
}