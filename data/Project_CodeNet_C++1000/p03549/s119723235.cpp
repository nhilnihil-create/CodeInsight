#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int x = 1;
    for (int i = 1 ; i <= m ; i++) x *= 2;
    cout << x * (1900 * m + 100 * (n - m));
}