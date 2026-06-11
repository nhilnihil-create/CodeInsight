#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

int main()
{
    LLONG A, B, C, K;
    cin >> A >> B >> C >> K;
    // K回の操作後，高橋君の数から中橋君の数を引くと
    // (-1)^K*(A-B)となる
    LLONG ans = K % 2 == 0 ? A - B : B - A;
    if (abs(ans) > 1e18)
    {
        cout << "Unfair" << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
