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
 
int div_cel(int n, int k) {
    return (n + k - 1) / k;
}

void solve() {
    int n,k;cin >> n >> k;
    for (int x, i = 1;i <= n;i ++) cin >> x;
    cout << div_cel(n - 1,k - 1);
}
 
 
int main() {
    solve();
    return 0;
}