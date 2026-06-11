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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(ALL(a));
    ll ma = *max_element(ALL(a));
    ll in = (max_element(ALL(a)) - a.begin());
    double d = 1000000005;
    double h = ma / 2.0;
    ll ii = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        double temp = abs(a[i] - h);
        if(temp<d){
            d = temp;
            ii = a[i];
        }
    }
    cout << ma << " " << ii << endl;
}