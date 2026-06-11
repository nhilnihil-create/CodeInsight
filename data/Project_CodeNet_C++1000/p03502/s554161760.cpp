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
    int n;
    cin >> n; 
    string s = to_string(n);
    int digit = 0;
    for (auto ss : s) {
        digit += ss - '0';
    }
    if (n % digit == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}


