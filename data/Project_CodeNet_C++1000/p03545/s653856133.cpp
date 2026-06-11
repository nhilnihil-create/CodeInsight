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
    int a, b, c, d;
    string s;
    cin >> s;
    a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            for (int k = -1; k <= 1; k += 2) {
                if (a + b * i + c * j + d * k == 7) {
                    cout << a;
                    cout << (i == 1 ? '+' : '-');
                    cout << b;
                    cout << (j == 1 ? '+' : '-');
                    cout << c;
                    cout << (k == 1 ? '+' : '-');
                    cout << d;
                    cout << "=7" << endl;
                    return 0;
                }
            }
        }
    }
}
