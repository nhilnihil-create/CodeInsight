#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, h, w;
    cin >> n >> h >> w;
    cout << (n - w + 1) * (n - h + 1) << endl;
}