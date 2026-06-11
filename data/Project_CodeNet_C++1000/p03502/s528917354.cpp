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
    int x;
	cin >> x;
	string s = to_string(x);
	int y = 0; 
	for (int i = 0 ; i < s.length() ; i++) y += s[i] - '0';
	if (x % y == 0) cout << "Yes";
	else cout << "No";
}