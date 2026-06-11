#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , m , x = 1;
    cin >> n >> m;
    for( int i = 1 ; i <= m ; i++ ) x *= 2;
    cout << x * ( 1900 * m + 100 * ( n - m ) );
}