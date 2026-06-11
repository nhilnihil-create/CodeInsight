#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
typedef pair<int, pair<int, int>> PP;
const double PI = 3.1415926535897932;   // acos(-1)
const double EPS = 1e-15;
const ll mod = 1e+9 + 7;
const int INF = 1001001001;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

int main(){
    int n;
    cin >> n;
    int sz = 1;
    for(int i = 0; i < n; ++i)  sz *= 2;
    vector<int> a(sz);
    for(int i = 0; i < sz; ++i) cin >> a[i];
    
    int res = 0;
    for(int k = 1; k < sz; ++k){
        int firstmax = max(a[k], a[0]), secondmax = min(a[k], a[0]);
        int subset = (k - 1) & k;
        while(subset){      // 部分集合列挙
            int hoge = a[subset];
            if(hoge > firstmax)     swap(hoge, firstmax);
            if(hoge > secondmax)    swap(hoge, secondmax);
            subset = (subset - 1) & k;
        }
        chmax(res, firstmax + secondmax);
        cout << res << "\n";
    }
}