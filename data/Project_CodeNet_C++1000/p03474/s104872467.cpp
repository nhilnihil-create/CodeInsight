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
    int a , b , m = 0;
    string s;
    cin >> a >> b >> s;
    for( int i = 0 ; i < a + b + 1; i ++ ) {
        if( i == a && s[i] != '-' ) m = 1; 
        else if( i != a && s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' &&  s[i] != '9' ) m = 1;
    }
    if( m == 1 ) cout << "No";
    else cout << "Yes";
}
