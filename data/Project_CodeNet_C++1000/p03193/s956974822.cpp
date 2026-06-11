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
    int n;
    int ans = 0;
    cin >> n;
    int h, w;
    cin >> h >> w;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) {
        cin >> a.at(i) >> b.at(i);
        if (a.at(i) >= h && b.at(i) >= w) ans++;
    }
    cout << ans << endl;
}