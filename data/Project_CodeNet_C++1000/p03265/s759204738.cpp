#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int disx = x2 - x1;
    int disy = y2 - y1;
    cout << x2 - disy << ' ' << y2 + disx << ' ' << x1 - disy << ' ' << y1 + disx << endl;
}
