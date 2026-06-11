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
    int n, a, b;
    cin >> n >> a >> b;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        int digit = 0;
        while (num > 0) {
            digit += num % 10;
            num /= 10;
        }
        if (digit >= a && digit <= b) {
            res += i;
        }
    }
    cout << res << endl;
}


