#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long int;
using i64 = int64_t;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
const ll INF = 1LL << 60;
int mod = (int)1e9 + 7;

int main() {
    i64 n;
    cin >> n;
    i64 l[86 + 1];
    l[0] = 2; l[1] = 1;
    for(int i = 2;i <= n;i++) l[i] = l[i-1] + l[i-2];
    cout << l[n] << endl;
}
