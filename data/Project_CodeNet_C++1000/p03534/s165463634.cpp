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
double eps = 1e-11;

int main() {
    string S;
    cin >> S;
    int len = S.size();
    int abc[3] = {0, 0, 0};
    for (int i = 0; i < len; i++) {
        abc[S[i] - 97]++;
    }
    int num = len / 3;
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        if (abc[i] != num && abc[i] != num + 1) {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
