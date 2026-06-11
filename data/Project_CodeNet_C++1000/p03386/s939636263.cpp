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
    int a , b , k;
    cin >> a >> b >> k;
	for( int i = a ; i <= b ; i++) {
		if( i <= a + k - 1 || i >= b - k + 1 ) cout << i << endl; 
	} 
}