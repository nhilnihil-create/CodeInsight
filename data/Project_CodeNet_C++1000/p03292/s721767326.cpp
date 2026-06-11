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
    int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort( a , a + 3 );
	cout << a[1] - a[0] + a[2] - a[1];
}
