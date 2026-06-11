#include <fstream>
#include <numeric>
#include <unordered_set>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
 
using namespace std;
 
#define ll long long
const int N = (ll)(2e5) + 100;

int a[N + 1];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm (int a, int b) {
    return a / gcd (a, b) * b;
}
 

void solve() {
    int x;cin >> x;
    int l = lcm(2, x);
    cout << l << " ";
}
 
int main() {
    solve();
    return 0;
}

// 41 59 31
// 59 41 31
// 31 41 59
