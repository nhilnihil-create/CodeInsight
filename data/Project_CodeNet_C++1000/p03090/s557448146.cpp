#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 1000000;

vector<pair<int, int>>v;
int n, N;

int main() {
    cin >> n;
    N = n/2*2+1;
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (i+j != N)v.push_back({i, j});
        }
    }
    cout << v.size() << endl;
    for (auto x : v) {
        cout << x.first << " " << x.second << endl;
    }
}
