#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>
#include <stdio.h>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}


int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int  x = x2 - x1, y = y2 - y1;
    printf("%d %d %d %d\n" ,x2 - y,y2 + x, x1 - y, y1 + x);
    return 0;
}
