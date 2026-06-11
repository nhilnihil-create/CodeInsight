#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main()
{
    int x[4], y[4];
    for (int i = 0; i < 2; ++i) cin >> x[i] >> y[i];
    
    int dx = x[1] - x[0];
    int dy = y[1] - y[0];


    x[2] = x[1] - dy, y[2] = y[1] + dx;
    x[3] = x[0] - dy, y[3] = y[0] + dx;
    
    printf("%d %d %d %d\n", x[2], y[2], x[3], y[3]);
    return 0;
}
