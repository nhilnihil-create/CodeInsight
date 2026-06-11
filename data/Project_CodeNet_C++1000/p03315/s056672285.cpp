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

#define for1(n) for (int i = 0 ; i < n ; i++)
#define for2(n) for (int j = 0 ; j < n ; j++)
#define for3(n) for (int k = 0 ; k < n ; k++)
#define for4(n) for (int l = 0 ; l < n ; l++)
#define forl(n) for (ll i = 0 ; i < n ; i++)

int main() {
    ios::sync_with_stdio(false);
 	string s;
 	cin >> s;
 	int x = 0;
 	for1(s.length()) {
 		if (s[i] == '+') x++;
 		else x--;
	}
	cout << x;
}