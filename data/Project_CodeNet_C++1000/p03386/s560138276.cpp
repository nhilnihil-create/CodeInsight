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
    
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = a; i <= min(b, a + k - 1); i++) {
        cout << i << endl;
    }
    for (int i = max(a + k, b - k + 1); i <= b; i++) {
        cout << i << endl;
    }
}


