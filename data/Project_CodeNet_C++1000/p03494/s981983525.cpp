#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <iomanip>
#include <complex>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const int N = 1e3 + 5, inf = 1e9, mod = 998244353;
using namespace std;

int main()
{
    IO
    int n, a, mn = inf;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        int tmp = 0;
        while(a % 2 == 0)
            a /= 2, tmp++;
        mn = min(mn, tmp);
    }
    cout << mn << '\n';
    return 0;
}