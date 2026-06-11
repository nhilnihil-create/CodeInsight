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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int c = 0;
        while (v[i] % 2 == 0) {
            v[i] /= 2;
            c++;
        }
        res += c;
    }
    cout << res << endl;
}
