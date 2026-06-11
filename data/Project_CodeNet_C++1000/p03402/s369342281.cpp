#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    string s[102] = {};
    for (int i = 0 ; i < 50 ; i++) {
        for (int j = 0 ; j < 100 ; j++) s[i] += '.';
    }
    for (int i = 50 ; i < 100 ; i++) {
        for (int j = 0 ; j < 100 ; j++) s[i] += '#';
    }
    b--;
    for (int i = 0 ; i < 50 ; i += 2) {
        for (int j = 0 ; j < 100 ; j += 2) {
            if (b == 0) break;
            s[i][j] = '#';
            b--;
        }
        if (b == 0) break;
    }
    a--;
    for (int i = 52 ; i < 100 ; i += 2) {
        for (int j = 0 ; j < 100 ; j += 2) {
            if (a == 0) break;
            s[i][j] = '.';
            a--;
        }
        if (a == 0) break;
    }
    cout << 100 << ' ' << 100 << '\n';
    for (int i = 0 ; i < 100 ; i++) cout << s[i] << '\n';
}