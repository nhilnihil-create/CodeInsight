//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

using namespace std;

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//{akari : 1D, yukari : 2D, maki : 3D} vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//{akane : ascending order, aoi : decending order} priority queue
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Libraries ---------------------------------//

//------------------------------- Dubug Functions ---------------------------//

inline void print()
{
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest)
{
    cout << first << ' ';
    print(rest...);
}

//------------------------------- Solver ------------------------------------//

void solve()
{
    i64 a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    i64 ans = 1e18;
    for (int i = 0; i <= 2 * max(x, y); i++)
    {
        ans = min(ans, a * max(0L, x - i / 2) + b * max(0L, y - i / 2) + c * i);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
