#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <math.h>
#include <functional>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
int main(){
    int n, k;
    cin >> n >> k;
    str s;
    cin >> s;
    s[k - 1] += 32;
    cout << s << endl;
    return 0;
}