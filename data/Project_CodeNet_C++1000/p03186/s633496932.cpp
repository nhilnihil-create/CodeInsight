#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    c = min(c, a + b + 1);
    cout << c + b << endl;
}
