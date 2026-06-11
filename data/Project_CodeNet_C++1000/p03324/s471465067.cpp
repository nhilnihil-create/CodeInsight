#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a , b;
    cin >> a >> b;
    if( b == 100 ) cout << (b + 1) * (int)pow( 100 , a );
    else cout << b * (int)pow( 100 , a );
}
