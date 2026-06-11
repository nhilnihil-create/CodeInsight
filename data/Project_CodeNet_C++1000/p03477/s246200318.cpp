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
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    if( a + b > c + d ) cout << "Left";
    else if( a + b == c + d ) cout << "Balanced";
    else cout << "Right";
}