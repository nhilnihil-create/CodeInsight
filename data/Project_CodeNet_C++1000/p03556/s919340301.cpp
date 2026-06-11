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
    long long n;
  	cin >> n;
  	bool a = 1;
  	long long i = 1;
  	while(a){
  	  	if(i * i > n){
  	    	cout << (i - 1) * (i - 1) << endl;
  	    	a = 0;
  	  	}
  		i++;
  	}
  	return 0;
}