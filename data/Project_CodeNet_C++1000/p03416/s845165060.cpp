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
    int a, b, c = 0;
    cin >> a >> b;
	for (int i = a ; i <= b ; i++) if (i / 10000 == i % 10 && i / 1000 % 10 == i % 100 / 10) c++;
	cout << c;	
}