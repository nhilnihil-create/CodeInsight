#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

int main() {
    int a, b;
    cin >> a >> b;
    int c = a*b;
    if(c%2 == 0) {
        cout << "Even" << endl;
    }else{
        cout << "Odd" << endl;
    }
    return 0;
}
