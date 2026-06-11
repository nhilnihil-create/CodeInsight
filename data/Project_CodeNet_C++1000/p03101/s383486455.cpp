#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << (H - h) * (W - w) << endl;
    return 0;
}

