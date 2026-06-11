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
    cin.tie();
    ll n , b;
    int a = 0;
    cin >> n;
    b = n;
    while( n >= 10 ) {
        a += n % 10;
        n /= 10;
    }
    a += n;
    if( b % a == 0 ) cout << "Yes";
    else cout << "No";
}

