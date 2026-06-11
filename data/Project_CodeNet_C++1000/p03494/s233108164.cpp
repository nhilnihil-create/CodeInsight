#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() { 
    int res = 0x3f3f3f3f;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int r = 0;
        while (a % 2 == 0) {
            r++;
            a /= 2;
        }
        res = min(res, r);
    }
    cout << res << endl;
}


