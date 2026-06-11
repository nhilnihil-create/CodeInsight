#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    long x, y;
    cin >> x >> y;

    long now = x;

    int count = 0;

    while (now <= y) {
        now*=2;
        count++;
    }

    cout << count << endl;

    return 0;
}