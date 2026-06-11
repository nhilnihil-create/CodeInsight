#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime> 
#include <memory.h>
#include <assert.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18 + 1;

int main() {
    string s;
    cin >> s;
    if(s.size() == 3) reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}