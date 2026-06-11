#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    ll x,y;
    cin >> x >> y;
    int len = 0;
    ll a = x;
    do {
        len++;
        a *= 2;
    } while (a <= y);
    cout << len << endl;
    return 0;
}