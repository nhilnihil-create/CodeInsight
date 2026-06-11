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

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int j = 11;
    bool y = 1;
    while (n) {
        bool y = 1;
        for (int k = 2 ; k < j ; k++) if (j % k == 0) y = 0;
        if (y && j % 5 == 1) n--, cout << j << ' ';
        j++;
    }
}
