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
    int res = 0;
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    for (int aa = 0; aa <= a; aa++) {
        for (int bb = 0; bb <= b; bb++) {
            for (int cc = 0; cc <= c; cc++) {
                if (aa * 500 + bb * 100 + cc * 50 == x) {
                    res++;
                }
            }
        }
    }
    cout << res << endl;
}


