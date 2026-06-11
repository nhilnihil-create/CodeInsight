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
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int x = 0;
    cin >> s;
    for( int i = 0 ; i < 3 ; i++ ) {
        if( s[i] == 'o' ) x++;
    }
    cout << 700 + x * 100;
}