#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 100010;

int a[Maxn];
int n, m, r;
double n2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    m = a[n - 1];
    n2 = 1.0 * m / 2;
    double dist = 1e9 + 10;
    for (int i = 0; i < n; ++i) {
        if (abs(a[i] - n2) < dist){
            r = a[i];
            dist = abs(a[i] - n2);
        }
    }
    cout << m << " " << r << endl;
}
