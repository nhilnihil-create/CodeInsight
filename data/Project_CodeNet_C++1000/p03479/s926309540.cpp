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
    ll x , y , c = 0 , a = 0;
    cin >> x >> y;
    c = x;
    while( c <= y ) {
        c *= 2;
        a++;
    }
    cout << a;
}
