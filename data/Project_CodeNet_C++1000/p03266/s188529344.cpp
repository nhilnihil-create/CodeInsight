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

int main() {
    ios::sync_with_stdio(false);
    ll n, k, a, b;
    cin >> n >> k;
    a = n / k;
    b = (n + k / 2) / k; 
    if (k % 2) cout << a * a * a;
	else cout << a * a * a + b * b * b;                                                     
}
/*
*/