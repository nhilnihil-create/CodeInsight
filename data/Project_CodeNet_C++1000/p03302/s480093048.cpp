#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a + b == 15) {
        cout << "+" << endl;
    } else if (a * b == 15) {
        cout << "*" << endl;
    } else {
        cout << "x" << endl;
    }

    return 0;
}
