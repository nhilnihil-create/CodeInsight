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
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, x, ans = 0;
    cin >> a >> b >> c >> x;
    for (int i = 0 ; i <= a ; i++) {
    	for (int j = 0 ; j <= b ; j++) {
    		for (int k = 0 ; k <= c ; k++) {
    			if (500 * i + 100 * j + 50 * k == x) ans++; 
			}
		}
	}  
    cout << ans;
}