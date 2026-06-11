#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, w;
    cin >> n >> h >> w;

    int H = n - h + 1;
    int W = n - w + 1;
    cout << H * W << endl;
}