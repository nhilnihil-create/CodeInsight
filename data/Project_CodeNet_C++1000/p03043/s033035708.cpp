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
#include <iomanip>
//
using ll = long long;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
#define outD(fpv) cout << setprecision(20) << fpv << endl;
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
inline void YES(bool cond) { cond ? puts("YES") : puts("NO"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { fill(arr.begin(), arr.end(), v); }
//template<typename Type> inline void sort(Type& arr, bool order = true){ sort(arr.begin(), arr.end(), order ? less<>() : greater<>()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
template<typename Type> inline void unique(Type& arr) { sort(arr); arr.erase(unique(arr.begin(), arr.end()), arr.end()); }
constexpr ll INF_I = numeric_limits<ll>::max();
constexpr ll BIGP = 1000000007L;
constexpr double INF_F = numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;
using P = pair<ll, ll>;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //
    ll N, K;
    cin >> N >> K;
    // 最初のサイコロだけでうまくいく場合
    double p = max(double(N - K+1) / N, 0.0);
    //
    rep(i, min(K-1,N))
    {
        ll s = i + 1;
        ll needScale = (K + s - 1) / s - 1;
        ll odds = 1;
        while (needScale != 0)
        {
            needScale >>= 1;
            odds *= 2;
        }
        p += 1.0 / double(odds*N);
    }
    //
    outD(p);
    //
    return 0;
}