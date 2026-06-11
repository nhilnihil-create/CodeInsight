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
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int i = 0;
  	while (i < n) {
    	string c;
    	cin >> c;
    	if(c == "W") {
    	  i++;
    	}
    	if(c == "P") { 
    	  i++;
    	}
    	if(c == "G") {
    	  i++;
    	}
    	if(c == "Y") {
    	  cout << "Four" << endl;
    	  break;
    	}
    	if(i == n - 1) {
    	  cout << "Three" << endl;
    	}
  	}
}
