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
   	string s;
   	cin >> s;
   	if (s[0] != s[1] && s[0] != s[2] && s[1] != s[2]) cout << "Yes";
   	else cout << "No";
}