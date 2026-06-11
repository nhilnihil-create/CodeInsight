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
    sort(v.begin(), v.end());
    int res = 1;
    int last = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > last) {
            res++;
        }
        last = v[i];
    }
    cout << res << endl;
}


