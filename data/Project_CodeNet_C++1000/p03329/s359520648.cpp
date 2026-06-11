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

int a[6] = {6, 36, 216, 1296, 7776, 46656}, b[5] = {9, 81, 729, 6561, 59049};  

int main() {
    ios::sync_with_stdio(false);
    int a[12] = {1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049}, d[100005] = {};  
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) d[i] = 100005;
    for (int i = 1 ; i <= n ; i++) {
    	for (int j = 0 ; j < 12 ; j++) if (i >= a[j]) d[i] = min(d[i], d[i - a[j]] + 1);
	}
	cout << d[n];
    
}