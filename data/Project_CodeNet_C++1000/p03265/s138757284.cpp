#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x = c - a, y = d - b;
    cout << c - y << ' ' << d + x << ' ' << a - y << ' ' << b + x << endl;

    return 0;
}