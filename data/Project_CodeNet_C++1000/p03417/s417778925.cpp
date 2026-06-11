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
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) cout << 1;
    else if (n == 1)  cout << m - 2;
    else if (m == 1) cout << n - 2;
    else cout << n * m - (2 * n + 2 * (m - 2));
}