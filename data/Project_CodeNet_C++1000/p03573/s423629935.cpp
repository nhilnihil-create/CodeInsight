#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a , b , c;
    cin >> a >> b >> c;
    if( a == b && a != c ) cout << c;
    else if( a == c && a != b ) cout << b;
    else if( b == a && b != c ) cout << c;
    else if( b == c && b != a ) cout << a;
    else if( c == a && c != b ) cout << b;
    else if( c == b && c != a ) cout << a;
    else cout << a;
}
