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
    int n = 100;
    cin >> a >> b;
    a--, b--;
    vector<string> vs(n + 1, string(n + 1, '.'));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vs[i][j] = '#';
        }
    }

    for (int i = 1; i <= n; i += 2) {
        for (int j = i + 3; j <= n; j += 2) {
            if (a > 0) {
                a--;
                vs[i][j] = '.';   
            }
        }
    }

    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j + 2 < i; j += 2) {
            if (b > 0) {
                b--;
                vs[i][j] = '#';
            }
        }
    }
    cout << "100 100" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout <<vs[i][j];
        }
        cout << endl;
    }
}
