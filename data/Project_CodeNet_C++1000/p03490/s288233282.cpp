#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
ll inf = llmax / 2;

bool xx[4010][16020];
bool yy[4010][16020];
vector<int> mv[2];

int main() {
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int mark = 0;
    int len = s.size();
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'F') {
            num++;
        } else {
            if (num > 0 || (mark == 0 && mv[0].size() == 0)) {
                mv[mark].push_back(num);
            }
            num = 0;
            mark = (mark + 1) % 2;
        }
    }
    mv[mark].push_back(num);
    for (int i = 0; i < 4010; i++) {
        fill(xx[i], xx[i] + 16020, false);
        fill(yy[i], yy[i] + 16020, false);
    }
    xx[0][mv[0][0] + 8010] = true;
    yy[0][8010] = true;
    int lenx = mv[0].size();
    for (int i = 1; i < lenx; i++) {
        for (int j = 0; j < 16020; j++) {
            if (xx[i - 1][j]) {
                xx[i][j + mv[0][i]] = true;
                xx[i][j - mv[0][i]] = true;
            }
        }
    }
    int leny = mv[1].size();
    for (int i = 0; i < leny; i++) {
        for (int j = 0; j < 16020; j++) {
            if (yy[i][j]) {
                yy[i + 1][j + mv[1][i]] = true;
                yy[i + 1][j - mv[1][i]] = true;
            }
        }
    }
    if (xx[lenx - 1][x + 8010] && yy[leny][y + 8010]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
