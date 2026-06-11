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
    int res = 0;
    int n;
    cin >> n;
    while (n > 0) {
        if (n % 10 == 2) res++;
        n /= 10;
    }
    cout << res << endl;
}


