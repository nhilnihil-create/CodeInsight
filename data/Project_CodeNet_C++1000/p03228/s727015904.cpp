#include "bits/stdc++.h"

using namespace std;

//------------------------------- Libraries --------------------------------//

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//akari : 1D, yukari : 2D, maki : 3D vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//akane : ascending order, aoi : decending order
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

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
    i64 a, b, k;
    cin >> a >> b >> k;
    for (int i = 0; i < k; i++)
    {
        if (i & 1)
        {
            b = b / 2 * 2;
            a += b / 2;
            b -= b / 2;
        }
        else
        {
            a = a / 2 * 2;
            b += a / 2;
            a -= a / 2;
        }
    }
    cout << a << ' ' << b << endl;
}

int main()
{
    solve();
    return 0;
}
