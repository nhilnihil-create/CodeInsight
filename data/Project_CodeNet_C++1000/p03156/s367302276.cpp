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
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++ ) {
        int p;
        cin >> p;
        if (p <= a) {
            c1++;
        } else if (p <= b) {
            c2++;
        } else {
            c3++;
        }
    }
    cout << min(c1, min(c2, c3)) << endl;
}


