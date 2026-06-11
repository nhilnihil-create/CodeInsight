#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n)  FOR(i, 0, n)
#define ASC(c) sort((c).begin(), (c).end())
#define DESC(c) sort((c).begin(), (c).end(), greater<int>())

#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1, dy = y2 - y1;

    int x3 = x2 - dy, y3 = y2 + dx;
    int x4 = x1 - dy, y4 = y1 + dx;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
