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
    int n;
    cin >> n;
    int a[3][n + 1];
    for (int i = 0 ; i <= 2 ; i++) for (int j = 0 ; j <= n ; j++) a[i][j] = 0;
    for (int i = 1 ; i <= 2 ; i++) for (int j = 1 ; j <= n ; j++) {
    	int b;
        cin >> b;
        a[i][j] = max (a[i - 1][j] , a[i][j - 1]) + b;
    }
    cout << a[2][n];
}