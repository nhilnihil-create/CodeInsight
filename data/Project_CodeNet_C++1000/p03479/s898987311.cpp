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
    long long int x, y;
    cin >> x >> y;
    int res = 0;
    while (x <= y) {
        res++;
        x *= 2;
    }
    cout << res << endl;
}


