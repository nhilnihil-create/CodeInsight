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
const int N = 1e5 + 5, inf = 1e9, mod = 998244353;
using namespace std;

int main()
{
    IO
    string a, b;
    cin >> a >> b;
    for (int i = 0, j = b.size() - 1; i < a.size(); i++, j--)
        if (a[i] != b[j])
            return cout << "NO\n", 0;
    cout << "YES\n";
    return 0;
}