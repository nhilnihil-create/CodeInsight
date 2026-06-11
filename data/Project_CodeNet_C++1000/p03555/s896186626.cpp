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

int a[10000000] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a , b;
    cin >>  a >> b;
    reverse( b.begin() , b.end() );
    if( a == b ) cout << "YES";
    else cout << "NO"; 
}
