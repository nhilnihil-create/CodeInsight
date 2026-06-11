#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
typedef long double ld;
typedef long long int ll;
const ll INF = (1LL << 63);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0; i < n;i++)
const int MAX = 1000000010;
int a[100];
void prime(int n) {
    while (n % 2 == 0) {
        a[2]++;
        n /= 2;
    }
    for (int i = 3; i <= n; i += 2) {
        while (n % i == 0) {
            a[i]++;
            n /= i;
        }
    }
}
const ll MOD = 1000000007;
int cnt(int n) {
    int res = 0;
    rep(i, 100) {
        if (a[i] >= n - 1) res++;
    }return res;
}
int main() {
    ll n,ans; cin >> n;
    if (n < 10) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        prime(i);
    }
    ans = cnt(75) + cnt(25) * (cnt(3)-1) + cnt(15) * (cnt(5)-1);
    ans += cnt(5) * (cnt(5) - 1) * (cnt(3) - 2) / 2;
    cout << ans << endl;
}