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
    int n;
	cin >> n;
  	int c = 0;
  	for( int i = 0 ; i < n ; i++ ){
    	int a;
		cin >> a;
    	while( true ){
      		if( a % 2 == 0 ) {
        		c++;
        		a /= 2;
      		} else break;
    	}
  	}
  	cout << c;
}
