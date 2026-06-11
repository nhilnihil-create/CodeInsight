#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin >> a;
    sort( a.begin() , a.end() );
    if( a[0] == 'a' && a[1] == 'b' && a[2] == 'c' ) cout << "Yes";
    else cout << "No";
} 