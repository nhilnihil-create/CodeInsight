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
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { std::fill(arr.begin(), arr.end(), v); }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline void reverse(Type& arr) { reverse(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
template<typename Type> inline void unique(Type& arr) { sort(arr); arr.erase(unique(arr.begin(), arr.end()), arr.end()); }
constexpr ll INF_I = std::numeric_limits<ll>::max();
constexpr ll BIGP = 1e9 + 7;
constexpr double INF_F = std::numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;
using P = pair<ll, ll>;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> Ss(M);
    rep(i, M)
    {
        ll k;
        cin >> k;
        vector<ll> S(k);
        rep(j, k)
        {
            cin >> S[j];
            --S[j];
        }
        Ss[i] = S;
    }
    vector<ll> p(M);
    rep(i, M) cin >> p[i];

    // スイッチの状態を巡回
    ll ans = 0;
    std::vector<bool> onOff(N);
    for (uint16_t bits = 0; bits < (1 << N); ++bits)
    {
        rep(i, N) onOff[i] = (bits & (1 << i));
        //
        bool okay = true;
        rep(i, Ss.size())
        {
            auto& S = Ss[i];
            int count = 0;
            rep(j, S.size())
            {
                count += onOff[S[j]];
            }
            if (count % 2 != p[i])
            {
                okay = false;
                break;
            }
        }
        if (okay)
        {
            ++ans;
        }
    }
    cout << ans;

    //
    return 0;
}