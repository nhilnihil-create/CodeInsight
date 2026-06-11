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
    int x;
    cin >> x;
  	ll c = 0;
  	for(ll i = 1; i <= 100; i++){
    	ll n = i;
  		for( int j = 2; j <= 10; j++){
    		n *= i;
      	    if( n <= x ) c = max( n , c );
        }
    }
    cout << c;
}
