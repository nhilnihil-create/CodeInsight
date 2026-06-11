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
    int x1 = 0, y1 = 0;
    int flag = 1;
    int t1 = 0;
    for (int i = 0; i < n; i++) {
        int t2, x2, y2;
        cin >> t2 >> x2 >> y2;
        int dist = abs(x2 - x1) + abs(y2 - y1);
        if (dist > (t2 - t1) || (t2 - t1 - dist) % 2 == 1) {
            flag = 0;
        }
        x1 = x2, y1 = y2;
        t1 = t2;
    }
    if (flag == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}


