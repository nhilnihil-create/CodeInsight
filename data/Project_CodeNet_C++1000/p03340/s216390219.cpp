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
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll inf = (1 << 30);
const int MOD = 1000000007;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    ll n,sum = 0; cin >> n; ll res = 0; int right = 0;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(left, n) {
        while (right < n && (sum^a[right]) == (sum + a[right])) {
            sum += a[right];
            right++;
        }
        res += right - left;
        if (right == left) right++;
        else sum -= a[left];
    }cout << res << endl;
}