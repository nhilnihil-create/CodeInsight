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

int ma(int n) {
    return (n + 9) / 10 * 10;
}

int mud(int n) {
    return ma(n) - n;
}

int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    
    int sum = ma(a) + ma(b) + ma(c) + ma(d) + ma(e);
    int sai = max({mud(a), mud(b), mud(c), mud(d), mud(e)});
    cout << sum - sai << endl;

    return 0;
}