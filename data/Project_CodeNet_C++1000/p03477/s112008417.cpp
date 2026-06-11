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
#include <queue>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b > c + d) cout << "Left";
    else if (a + b < c + d) cout << "Right";
    else cout << "Balanced";
}