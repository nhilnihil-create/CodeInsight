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
    cin >> n;
    vector <ll> a(n), b(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    b = a;
    sort (b.begin(), b.end());
    int c = (n - 2) / 2;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] <= b[c]) cout << b[c + 1] << endl;
        else cout << b[c] << endl;
    }
}
/*
*/