#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool p = min(abs(a - c), max(abs(a - b), (abs(b - c)))) <= d;
    if(p) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
