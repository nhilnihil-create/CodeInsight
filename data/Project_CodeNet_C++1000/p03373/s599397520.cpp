#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int cost = 0;
    int cost_min = INFINITY;

    for (int i = 0; i <= 100000; ++i) {
        cost = i * 2 * c;
        if (i < x)cost += (x - i) * a;
        if (i < y)cost += (y - i) * b;
        if (cost < cost_min)cost_min = cost;
        }
    print(cost_min);
}