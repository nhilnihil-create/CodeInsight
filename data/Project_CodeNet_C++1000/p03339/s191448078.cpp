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
    string s;
    cin >> n >> s;
    int w[n] = {}, e[n] = {};
    for (int i = 1 ; i < n ; i++) {
    	if (s[i - 1] == 'W') {
    		w[i] = w[i - 1] + 1;
		}
		else w[i] = w[i - 1];
	} 
	for (int i = n - 2 ; i >= 0 ; i--) {
    	if (s[i + 1] == 'E') {
    		e[i] = e[i + 1] + 1;
		} 
    	else e[i] = e[i + 1];
  	}	
  	int m = n;
  	for (int i = 0 ; i < n ; i++) {
  		m = min(m, w[i] + e[i]);
	}
	cout << m;
}