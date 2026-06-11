#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int tryt=pow(2,m);
    cout << tryt*(n*100+m*1800) << "\n";

    return 0;
}