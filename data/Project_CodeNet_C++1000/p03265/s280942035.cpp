#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int main(){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << x2-(y2-y1) << " " << y2+(x2-x1) << " " << x1-(y2-y1) << " " << y1+(x2-x1) << endl;
    return 0;
}
