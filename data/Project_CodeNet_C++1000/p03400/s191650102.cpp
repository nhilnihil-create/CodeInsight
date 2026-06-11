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
    int n, d, x;
    cin >> n >> d >> x; 
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        x += d / a + (d % a > 0 ? 1 : 0);
    }
    cout << x << endl;
}
