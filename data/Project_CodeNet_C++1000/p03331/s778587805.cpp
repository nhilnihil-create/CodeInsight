#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
signed main() {
    ll n;
    cin >> n;
  if (n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000) {
    cout<<10<<endl;
  }
  else {
        ll a = n / 100000;
        ll b = n % 100000 / 10000;
        ll c = n % 10000 / 1000;
        ll d = n % 1000 / 100;
        ll e = n % 100 / 10;
        ll f = n % 10;
        cout << a + b + c + d + e + f << endl;
  }
}