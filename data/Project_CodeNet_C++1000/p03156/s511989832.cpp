#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n, a, b;
    int x = 0;
    int y = 0, z = 0;
    cin >> n >> a >> b;
    vector<int> p(n);
    rep(i, n) {
        cin >> p.at(i);
        if (p.at(i) <= a) x++;
        else if (p.at(i) <= b) y++;
        else z++;
    }
    cout << min(x, min(y, z)) << endl;
}