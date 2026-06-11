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
	int n , x , a = 1001 , m;
    cin >> n >> x;
    for (int i = 0 ; i < n ; i++) {
        cin >> m;
        a = min(a, m);
        x -= m;
    }
    cout << n + x / a;
	
}