#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;


int main() {
    int H, W;
    cin >> H >> W;
    if (H > W)cout << H - 1;
    else cout << H;
}