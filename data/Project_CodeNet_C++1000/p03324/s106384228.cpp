#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int d,n;
    cin >> d >> n;
    if(d == 0) {
        if (n != 100) cout << n << endl;
        else cout << 101 << endl;
    }
    else if (d == 1) {
        if (n != 100) cout << n*100 << endl;
        else cout << 10100 << endl;
    }
    else {
        if (n != 100) cout << n*10000 << endl;
        else cout << 1010000 << endl;
    }
    return 0;
}