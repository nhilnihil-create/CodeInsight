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
    string a , b;
    cin >> a >> b;
    sort( a.begin() , a.end() );
    sort( b.begin() , b.end() );
    reverse( b.begin() , b.end() );
    if( a < b ) cout << "Yes";
    else cout << "No";
}
