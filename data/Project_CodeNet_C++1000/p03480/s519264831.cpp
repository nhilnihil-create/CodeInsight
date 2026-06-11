#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    string S;
    cin >> S;
    
    int n = S.size();

    int sn = 0;
    char val = 'a';
    while (sn <= n) {
        sn++;

        int x = sn - 1;
        int y = n - sn;
        if (x > n || y < 0) break;

        // cout << "sn: " << sn << ", x: " << x << ", y: " << y << endl;
        if (x < y) continue;
        if (S.at(x) != S.at(y)) break;
        if (val == 'a') val = S.at(x);
        if (val != S.at(x)) break;
    }

    cout << (sn - 1) << endl;
}