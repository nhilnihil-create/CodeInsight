#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <bitset>
#include <queue>

using namespace std;

void solve() {
    int r; cin >> r;
    if(r < 1200) cout << "ABC";
    else if (r < 2800) cout << "ARC";
    else cout << "AGC";
}

int main() {
    solve();
    return 0;
}