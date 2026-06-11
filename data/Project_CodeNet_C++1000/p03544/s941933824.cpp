#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll a = 1;
  	ll b = 2;
    if(n != 1){
    	for(int i = 2 ; i <= n ; i++){
    		ll tmp = a;
    		a = a + b;
    	  	b = tmp;
    	}
    	cout << a;
  	}
  	else cout << 1;
}