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
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 1; i <= a; i++) {
        if (i < a) res++;
        else if (i == a && i <= b) res++;
    }
    cout << res << endl;
}
