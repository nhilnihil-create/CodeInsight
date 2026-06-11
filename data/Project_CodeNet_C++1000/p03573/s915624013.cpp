#include <iostream>
#include<cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
	int a, b, c;
    cin >> a >> b >> c;
    if (a == b && a != c) cout << c;
    else if (a == c && a != b) cout << b;
    else if (b == a && b != c) cout << c;
    else if (b == c && b != a) cout << a;
    else if (c == a && c != b) cout << b;
    else if (c == b && c != a) cout << a;
    else cout << a;
}
