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
    int n, k;
    cin >> n >> k;
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (num <= k) {
            num *= 2;
        } else {
            num += k;
        }
    }
    cout << num << endl;
}


