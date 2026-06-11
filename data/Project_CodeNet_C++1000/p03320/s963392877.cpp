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

vector<ll> v;

int ketasum(ll n) {
    int ans = 0;
    while (true) {
        ans += n % 10;
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    return ans;
}

vector<ll> q;
vector<ll> p;

int main() {
    ll K;
    cin >> K;
    for (int i = 0; i < 100000; i++) {
        q.push_back(i);
    }
    for (int i = 0; i < 12; i++) {
        ll num = 10;
        for (int j = 0; j < i; j++) {
            num *= 10;
        }
        for (int j = 10000; j < 100000; j++) {
            q.push_back(j * num + num - 1);
        }
    }
    int len = q.size();
    double min = q[len - 1] * 1.0 / (ketasum(q[len - 1]) * 1.0);
    for (int i = len - 1; i >= 0; i--) {
        double now = q[i] * 1.0 / (ketasum(q[i]) * 1.0);
        if (now <= min) {
            p.push_back(q[i]);
            min = now;
        }
    }
    int len2 = p.size();
    int c = 0;
    for (int i = len2 - 1; i >= 0; i--) {
        cout << p[i] << endl;
        c++;
        if (c == K) {
            break;
        }
    }
}
