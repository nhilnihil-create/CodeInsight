#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>
#include <unordered_map>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define ALL(v) v.begin(), v.end()

/* デカい配列はここで宣言 */

int main(int argc, char const *argv[])
{
    vector<ll> a;
    for (ll i = 0; i < 4; i++)
    {
        ll s;
        cin >> s;
        a.push_back(s);
    }
    sort(ALL(a));
    if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}