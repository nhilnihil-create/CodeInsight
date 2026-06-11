//
#include <vector>
#include <set>
#include <map>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <bitset>
//
using ll = long long;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
#define outD(fpv) cout << setprecision(20) << fpv << endl;
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { std::fill(arr.begin(), arr.end(), v); }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
constexpr double BIGP = 1000000007L;
constexpr double INF_I = std::numeric_limits<ll>::max();
constexpr double INF_F = std::numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll r, D, x;
    cin >> r >> D >> x;
    rep(i,10)
    {
        x = r * x - D;
        cout << x << endl;
    }
    return 0;
}