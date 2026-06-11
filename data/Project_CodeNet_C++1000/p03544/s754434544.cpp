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
    int n;
    cin >> n;
    ll a = 2 , b = 1 , x;
    if( n != 1 ){
    	for(int i = 2 ; i <= n ; i++){
    		x = b;
    		b += a;
    	  	a = x;
    	}
    	cout << b;
    } else cout << 1;
}
