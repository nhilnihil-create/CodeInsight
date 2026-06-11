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
    unordered_set<char> us;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        us.insert(c);
    }
    if (us.size() == 3) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }
}
