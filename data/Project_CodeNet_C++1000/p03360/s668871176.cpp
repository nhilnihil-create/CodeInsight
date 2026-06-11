#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower, islower
#include <math.h>

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
//using ll = long long; using ld = long double;
//using P = pair<int, int>;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << a + b + c + max({a, b, c}) * ((1 << k) -1) << endl;
    return 0;
    //g++ <filename> -std=c++11でコンパイル必要
}

